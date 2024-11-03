#ifndef ORCOMPONENT_H
#define ORCOMPONENT_H

#include"LogicComponent.h"

class OrComponent:public LogicComponent{
    public:
    OrComponent();
    OrComponent(size_t inputSize);
    bool evaluate() override;

};

#endif