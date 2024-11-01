#include "LogicControl.h"

LogicControl::LogicControl(){
    for(size_t i=0; i<8; ++i) {
        for(size_t j=0; j<8; ++j) {
            pointMat[i][j].changeValue(false);
        }
        inputArr[i].changeValue(false);
        outputArr[i].changeValue(false);
    }
}

void LogicControl::addComponent(LogicComponent *component) {
    currentComponents.push_back(component);
}

void LogicControl::removeComponent(LogicComponent *component) {
    component->changeValue(false);
    const auto it = find(currentComponents.begin(), currentComponents.end(), component);
    if(*it == component) {
        currentComponents.erase(it);
    }
}

void LogicControl::connectInputToMat(const size_t componentIndex, const size_t inputIndex, const pair<size_t,size_t> &position) {
    if(position.first < 8 && position.second < 8)
        currentComponents[componentIndex]->connectInput(&pointMat[position.first][position.second],inputIndex);
}

void LogicControl::connectOutputToMat(const size_t componentIndex, const pair<size_t, size_t> &position) {
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

void LogicControl::evaluateAllComponents() {
    for(const auto &component : currentComponents)
        component->evaluate();

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








