#ifndef ORCOMPONENT_H
#define ORCOMPONENT_H

#include"LogicComponent.h"

class OrComponent:public LogicComponent{
    public:
    OrComponent();
    bool evaluate() override;

};

#endif