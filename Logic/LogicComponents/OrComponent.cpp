#include "OrComponent.h"

OrComponent::OrComponent() {
    alterComponentID(1);
}

OrComponent::OrComponent(size_t inputSize): LogicComponent(inputSize)
{}


bool OrComponent::evaluate(){
    for(size_t i = 0; i < getInConnectionSize(); i++) {
        if(getInConnection(i)->getValue()) {
            setOutValue(true);
            return true;
        }
    }
    setOutValue(false);
    return false;
}