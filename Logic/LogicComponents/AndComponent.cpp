#include "AndComponent.h"

bool AndComponent::evaluate() {
    for(size_t i = 0; i < getSizeOfInputs(); i++) {
        if(!(getInput(i))) {
            setOutput(false);
            return false;
        }
    }
    setOutput(true);
    return true;
}

void AndComponent::addAllInputs(size_t size) {
    for(size_t i = 0; i < size; i++) {
        addNewInput(false);
    }
}

void AndComponent::changeInput(bool value, size_t index) {
    getInput(index) = value;
}



