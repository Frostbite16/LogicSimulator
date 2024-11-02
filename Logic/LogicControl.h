
#ifndef LOGICCONTROL_H
#define LOGICCONTROL_H
#include "LogicComponents/LogicComponent.h"
#include<vector>
#include<algorithm>



class LogicControl:public LogicComponent{
    LogicPoint pointMat[8][8];
    LogicPoint inputArr[8];
    LogicPoint outputArr[8];
    std::vector<LogicComponent*> currentComponents;
    std::vector<LogicComponent*> wires;
public:
    LogicControl();
    void addComponent(LogicComponent* component);
    void removeComponent(LogicComponent* component);

    void connectInputToMat(size_t componentIndex,size_t inputIndex, const std::pair<size_t, size_t> &position);
    void connectOutputToMat(size_t componentIndex , const std::pair<size_t, size_t> &position);

    void connectInputToArr(size_t componentIndex, size_t index, size_t position);
    void connectOutputToAr(size_t componentIndex, size_t position);

    void setInputValue(size_t index, bool value);

    bool evaluate() override;

    void removeAllComponents();
};

#endif //LOGICCONTROL_H
