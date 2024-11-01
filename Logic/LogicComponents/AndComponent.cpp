#include "AndComponent.h"

bool AndComponent::evaluate() {
    for(size_t i = 0; i < getInConnectionSize(); i++) {
        if(!(getInConnection(i)->getValue())) {
            setOutValue(false);
            return false;
        }
    }
    setOutValue(true);
    return true;
}







