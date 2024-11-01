#include "LogicControl.h"

LogicControl::LogicControl(){
    for(size_t i=0; i<8; ++i) {
        for(size_t j=0; j<8; ++j) {
            pointMat[i][j].changeValue(2);
        }
        inputArr[i].changeValue(0);
        outputArr[i].changeValue(0);
    }
}

void LogicControl::addComponent(LogicComponent *component) {
    currentComponents.push_back(component);
}

void LogicControl::removeComponent(LogicComponent *component) {
    vector<LogicComponent*>::iterator local;
    component->changeValue(false);
    local = find(currentComponents.begin(), currentComponents.end(), component);
    if(*local == component) {
        currentComponents.erase(local);
    }
}

void LogicControl::connectInputToMat(size_t componentIndex,size_t inputIndex, const pair<size_t,size_t> &input) {
    if(input.first < 8 && input.second < 8)
        currentComponents[componentIndex]->connectInput(&pointMat[input.first][input.second],inputIndex);
}

void LogicControl::connectOutputToMat(size_t componentIndex, const pair<size_t, size_t> &position) {
    if(position.first < 8 && position.second < 8)
        currentComponents[componentIndex]->connectOutput(&pointMat[position.first][position.second]);
}




