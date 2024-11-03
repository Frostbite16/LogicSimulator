//
// Created by vboxuser on 01/11/2024.
//

#ifndef WIRE_H
#define WIRE_H
#include "LogicComponent.h"


class Wire:public LogicComponent{
public:
    Wire();
    Wire(std::size_t inputSize);
    bool evaluate() override;
};



#endif //WIRE_H
