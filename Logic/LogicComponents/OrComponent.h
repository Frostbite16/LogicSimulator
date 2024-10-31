#ifndef ORCOMPONENT_H
#define ORCOMPONENT_H

#include"LogicComponent.h"

class OrComponent:public LogicComponent{
    public:
    bool evaluate() override;

};

#endif