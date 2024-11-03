//
// Created by vboxuser on 01/11/2024.
//

#include "wire.h"

Wire::Wire() {
    alterComponentID(0);
}

Wire::Wire(std::size_t inputSize): LogicComponent(inputSize){

}


bool Wire::evaluate() {
    setOutValue(getInConnection(0)->getValue());
    return true;
}
