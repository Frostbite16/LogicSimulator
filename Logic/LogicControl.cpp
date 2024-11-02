#include "LogicControl.h"

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
    component->changeValue(false);
    const auto it = find(currentComponents.begin(), currentComponents.end(), component);
    if(it != currentComponents.end()) {
        currentComponents.erase(it);
    }
}

void LogicControl::connectInputToMat(const size_t componentIndex, const size_t inputIndex, const std::pair<size_t,size_t> &position) {
    if(position.first < 8 && position.second < 8)
        currentComponents[componentIndex]->connectInput(&pointMat[position.first][position.second],inputIndex);
}

void LogicControl::connectOutputToMat(const size_t componentIndex, const std::pair<size_t, size_t> &position) {
    if(position.first < 8 && position.second < 8)
        currentComponents[componentIndex]->connectOutput(&pointMat[position.first][position.second]);
}

void LogicControl::connectInputToArr(const size_t componentIndex, const size_t index, const size_t position) {
    if(position < 8)
        currentComponents[componentIndex]->connectInput(&inputArr[position], index);
}

void LogicControl::connectOutputToAr(const size_t componentIndex, const size_t position) {
    if(position < 8)
        currentComponents[componentIndex]->connectOutput(&outputArr[position]);
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








