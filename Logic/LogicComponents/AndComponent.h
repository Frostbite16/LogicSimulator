//
// Created by vboxuser on 29/10/2024.
//

#ifndef ANDCOMPONENT_H
#define ANDCOMPONENT_H

#include "LogicComponent.h"

class AndComponent:LogicComponent{
    public:
    bool evaluate() override;
    void addAllInputs(size_t size) override;
    void changeInput(bool value, size_t index) override;
};

#endif //ANDCOMPONENT_H
