
#ifndef LOGICCONTROL_H
#define LOGICCONTROL_H
#include "LogicComponents/LogicComponent.h"
#include<vector>
#include<algorithm>



class LogicControl:public LogicComponent {
    LogicPoint pointMat[8][8];
    LogicPoint inputArr[8];
    LogicPoint outputArr[8];
    std::vector<LogicComponent*> currentComponents;
    std::vector<LogicComponent*> wires;

    LogicComponent* searchComponent(const LogicComponent* component);


public:
    LogicControl();
    void addComponent(LogicComponent* component);
    void removeComponent(LogicComponent* component);

    void connectInputToMat(const LogicComponent* component, size_t inputIndex, const std::pair<size_t, size_t> &position);
    void connectOutputToMat(const LogicComponent* component, const std::pair<size_t, size_t> &position);
    void connectOutputToInput(const LogicComponent* component1, const LogicComponent* component2, size_t inputIndex);

    void connectWireInputToMat(const LogicComponent* wire, const std::pair<size_t, size_t> &position);
    void connectWireOutToMat(const LogicComponent* wire, const std::pair<size_t, size_t> &position);
    void connectWireToInput(const LogicComponent* wire, const LogicComponent* component, size_t inputIndex);

    void connectInputToArr(const LogicComponent* component, size_t index, size_t position);
    void connectOutputToArr(const LogicComponent* component, size_t position);

    void connectWireInToArr(const LogicComponent *wire, size_t position);
    void connectWireOutToArr(const LogicComponent *wire, size_t position);

    void setInputValue(size_t index, bool value);

    bool evaluate() override;

    void removeAllComponents();
};

#endif //LOGICCONTROL_H
