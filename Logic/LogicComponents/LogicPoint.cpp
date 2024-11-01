//
// Created by vboxuser on 01/11/2024.
//

#include "LogicPoint.h"

LogicPoint::LogicPoint() {
    currentValue = 2;
}

void LogicPoint::changeValue(bool value) {
    currentValue = value;
}

short& LogicPoint::getValue() {
    return currentValue;
}

void LogicPoint::setPosition(pair<size_t, size_t> position) {
    this->position = position;
}

pair<size_t, size_t> LogicPoint::getPosition() {
    return position;
}





