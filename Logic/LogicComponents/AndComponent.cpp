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







