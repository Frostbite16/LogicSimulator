//
// Created by vboxuser on 01/11/2024.
//

#include "wire.h"

bool wire::evaluate() {
    setOutValue(getInConnection(0)->getValue());
}
