#include "OrComponent.h"

bool OrComponent::evaluate(){
    for(size_t i = 0; i < getSizeOfInputs(); i++) {
        if((getInput(i))) {
            setOutput(true);
            return true;
        }
    }
    setOutput(false);
    return false;
}