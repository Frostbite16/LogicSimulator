#include "LogicComponent.h"

LogicComponent::LogicComponent() {
    output=false;
}


void LogicComponent::addNewInput(bool value) {
    inputs.push_back(value);
}

_Bit_reference LogicComponent::getInput(size_t index) {
    return inputs[index];
}

void LogicComponent::addAllInputs(size_t size) {
    for(size_t i = 0; i < size; i++) {
        addNewInput(false);
    }
}

void LogicComponent::changeInput(bool value, size_t index) {
    getInput(index) = value;
}

size_t LogicComponent::getSizeOfInputs() {
    return inputs.size();
}



bool LogicComponent::getOutput() const {
    return output;
}

