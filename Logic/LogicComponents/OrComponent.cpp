#include "OrComponent.h"

bool OrComponent::evaluate(){
    for(size_t i = 0; i < getInConnectionSize(); i++) {
        if((getInConnection(i)->getValue())) {
            setOutValue(1);
            return 1;
        }
    }
    setOutValue(0);
    return 0;
}