

#ifndef ANDCOMPONENT_H
#define ANDCOMPONENT_H

#include "LogicComponent.h"

class AndComponent:public LogicComponent{
    public:
    bool evaluate() override;
};

#endif //ANDCOMPONENT_H
