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

size_t LogicComponent::getSizeOfInputs() {
    return inputs.size();
}


bool LogicComponent::getOutput() const {
    return output;
}

