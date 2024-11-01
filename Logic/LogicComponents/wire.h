//
// Created by vboxuser on 01/11/2024.
//

#ifndef WIRE_H
#define WIRE_H
#include "LogicComponent.h"


class wire:public LogicComponent{
public:
    bool evaluate() override;
};



#endif //WIRE_H
