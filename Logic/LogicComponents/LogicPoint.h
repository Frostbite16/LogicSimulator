//
// Created by vboxuser on 01/11/2024.
//

#ifndef LOGICPOINT_H
#define LOGICPOINT_H
#include <vector>

using namespace std;

class LogicPoint {
    short currentValue;
    pair<size_t,size_t> position;
    public:
    LogicPoint();
    void changeValue(bool value);
    short& getValue();
    void setPosition(pair<size_t,size_t> position);
    pair<size_t,size_t> getPosition();

    virtual ~LogicPoint();
};



#endif //LOGICPOINT_H
