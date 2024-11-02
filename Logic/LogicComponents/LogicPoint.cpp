//
// Created by vboxuser on 01/11/2024.
//

#include "LogicPoint.h"

LogicPoint::LogicPoint() {
    currentValue = 0;
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





