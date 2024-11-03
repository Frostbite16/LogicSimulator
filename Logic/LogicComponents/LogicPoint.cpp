//
// Created by vboxuser on 01/11/2024.
//

#include "LogicPoint.h"

LogicPoint::LogicPoint() {
    currentValue = 0;
    connectedTo = this; // Quando um LogicPoint é criado, essa variavel aponta pra o próprio ponto
}

void LogicPoint::setConnectTo(LogicPoint* local){
    connectedTo = local;
}

LogicPoint* LogicPoint::getConnectedTo() const{
    return connectedTo;
}



void LogicPoint::changeValue(const bool value) {
    currentValue = value;
}

short& LogicPoint::getValue() {
    return currentValue;
}

void LogicPoint::setPosition(const std::pair<std::size_t, std::size_t> &position) {
    this->position = position;
}

std::pair<std::size_t, std::size_t> LogicPoint::getPosition() {
    return position;
}





