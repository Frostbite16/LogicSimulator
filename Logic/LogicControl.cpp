#include "LogicControl.h"

#include <stdexcept>

LogicComponent* LogicControl::searchComponent(const LogicComponent* component) {
    const auto it = find(currentComponents.begin(), currentComponents.end(), component);
    if(it == currentComponents.end()) {
        throw std::invalid_argument("Component not found");
    }
    return *it;
}

LogicComponent *LogicControl::searchWire(const LogicComponent *wire) {
    const auto it = find(wires.begin(), wires.end(), wire);
    if(it == wires.end()) {
        throw std::invalid_argument("Component not found");
    }
    return *it;
}


LogicControl::LogicControl(){
    for(size_t i=0; i<8; ++i) {
        for(size_t j=0; j<8; ++j) {
            pointMat[i][j].changeValue(false);
            pointMat[i][j].setPosition(std::pair<int,int>(i,j));
        }
        inputArr[i].changeValue(false);
        inputArr[i].setPosition(std::pair<int,int>(0,i));
        outputArr[i].changeValue(false);
        outputArr[i].setPosition(std::pair<int,int>(0,i));

    }
}

void LogicControl::addComponent(LogicComponent *component) {
    if(component!=nullptr) {
        if(component->getComponentID()) {
            currentComponents.push_back(component);
            return;
        }
        wires.push_back(component);
    }
}

void LogicControl::removeComponent(LogicComponent *component) {
    searchComponent(component);
    component->changeValue(false);
    const auto it = find(currentComponents.begin(), currentComponents.end(), component);
    if(it != currentComponents.end()) {
        currentComponents.erase(it);
    }
}

void LogicControl::connectInputToMat(const LogicComponent* component, const size_t inputIndex, const std::pair<size_t,size_t> &position) {
    LogicComponent* pointerToComponent = searchComponent(component);
    if(position.first < 8 && position.second < 8)
        pointerToComponent->connectInput(&pointMat[position.first][position.second],inputIndex);
}

void LogicControl::connectOutputToMat(const LogicComponent* component, const std::pair<size_t, size_t> &position) {
    LogicComponent* pointerToComponent = searchComponent(component);
    if(position.first < 8 && position.second < 8)
        pointerToComponent->connectOutput(&pointMat[position.first][position.second]);
}

void LogicControl::connectOutputToInput(const LogicComponent* component1, const LogicComponent* component2, size_t inputIndex) {
    LogicComponent* pointerToComponent1 = searchComponent(component1);
    LogicComponent* pointerToComponent2 = searchComponent(component2);

    pointerToComponent1->connectOutput(pointerToComponent2->getInConnection(inputIndex));
}

void LogicControl::connectWireInputToMat(const LogicComponent *wire, const std::pair<size_t, size_t> &position) {
    LogicComponent* pointerToWire = searchWire(wire);
    if(position.first < 8 && position.second < 8)
        pointerToWire->connectInput(&pointMat[position.first][position.second],0);
}

void LogicControl::connectWireOutToMat(const LogicComponent *wire, const std::pair<size_t, size_t> &position) {
    LogicComponent* pointerToWire = searchWire(wire);
    if(position.first < 8 && position.second < 8)
        pointerToWire->connectOutput(&pointMat[position.first][position.second]);
}

void LogicControl::connectWireToInput(const LogicComponent *wire, const LogicComponent *component, size_t inputIndex) {
    LogicComponent* pointerToWire = searchWire(wire);
    LogicComponent* pointerToComponent = searchComponent(component);

    pointerToWire->connectOutput(pointerToComponent->getInConnection(inputIndex));
}

void LogicControl::connectInputToArr(const LogicComponent* component, const size_t index, const size_t position) {
    LogicComponent* pointerToComponent = searchComponent(component);
    if(position < 8)
        pointerToComponent->connectInput(&inputArr[position], index);
}

void LogicControl::connectOutputToArr(const LogicComponent* component, const size_t position) {
    LogicComponent* pointerToComponent = searchComponent(component);
    if(position < 8)
        pointerToComponent->connectOutput(&outputArr[position]);
}

void LogicControl::connectWireInToArr(const LogicComponent *wire, size_t position) {
    LogicComponent* pointerToWire = searchWire(wire);
    if(position < 8)
        pointerToWire->connectInput(&inputArr[position],0);
}

void LogicControl::connectWireOutToArr(const LogicComponent *wire, size_t position) {
    LogicComponent* pointerToWire = searchWire(wire);
    if(position < 8)
        pointerToWire->connectOutput(&outputArr[position]);
}

void LogicControl::evaluateWires() {
    for(const auto &wire : wires)
        wire->evaluate();
}


bool LogicControl::evaluate() {
    for(const auto &component : currentComponents)
        component->evaluate();
    return true;

}

void LogicControl::setInputValue(const size_t index, const bool value) {
    inputArr[index].changeValue(value);
}


void LogicControl::removeAllComponents() {
    for(const auto &component : currentComponents) {
        component->changeValue(false);
    }
    currentComponents.clear();
}








