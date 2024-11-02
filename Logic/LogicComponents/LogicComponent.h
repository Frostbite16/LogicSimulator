#ifndef LOGICCOMPONENT_H
#define LOGICCOMPONENT_H

#include<vector>
#include<algorithm>

#include "LogicPoint.h"


class LogicComponent: public LogicPoint{
    std::vector<LogicPoint*> inConnections;
    LogicPoint* outConnection;
    bool savedValue;
    size_t numInputs;
    short componentID;
protected:
    void addNewInConnection(LogicPoint* local);
    void addNewOutConnection(LogicPoint* local);
    LogicPoint*& getInConnection(size_t index);
    LogicPoint*& getOutConnection();
    void setOutValue(bool value);
    void alterComponentID(short componentID);

public:
    LogicComponent();
    explicit LogicComponent(size_t numImputs);
    void initializeComponent();
    void connectInput(LogicPoint* local, size_t index);
    void connectOutput(LogicPoint* local);
    bool getOutValue() const;
    bool searchInConnection(const LogicPoint* local);
    size_t getInConnectionSize() const;
    short getComponentID();
    virtual bool evaluate() = 0;
    virtual ~LogicComponent();
};

#endif //LOGICCOMPONENT_H
