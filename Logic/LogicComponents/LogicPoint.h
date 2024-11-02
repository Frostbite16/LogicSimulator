//
// Created by vboxuser on 01/11/2024.
//

#ifndef LOGICPOINT_H
#define LOGICPOINT_H
#include <vector>


class LogicPoint {
    short currentValue;
    std::pair<std::size_t,std::size_t> position;
    public:
    LogicPoint();
    void changeValue(bool value);
    short& getValue();
    void setPosition(const std::pair<std::size_t, std::size_t> &position);
    std::pair<std::size_t,std::size_t> getPosition();

};



#endif //LOGICPOINT_H
