

#ifndef ANDCOMPONENT_H
#define ANDCOMPONENT_H

#include "LogicComponent.h"

class AndComponent:public LogicComponent{
    public:
    AndComponent();
    AndComponent(size_t inputSize);
    bool evaluate() override;
};

#endif //ANDCOMPONENT_H
