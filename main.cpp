#include "Logic/LogicControl.h"
#include "Logic/LogicComponents/OrComponent.h"
#include "Logic/LogicComponents/AndComponent.h"
#include "Logic/LogicComponents/wire.h"
#include<iostream>

/*
 *  Workflow:
 *      -Criar Componentes Normais
 *      -Criar Fios
 *
 *      -Apos conectar qualquer um dos componentes
 *          - Rodar evaluate para fios (se não tiver nenhum fio na cena, essa função não atualiza nada)
 *          - Atualizar entrada dos componentes
 *          - Rodar evaluate para componentes
 *
 *  Remoçao dos componentes deve ser feita:
 *      - Com função removeComponents ou removeAllComponetes
 *      - com delete component na main
 *
 *  Todos os inputs dos componentes são do mesmo tipo que os pontos da matrix, assim a variavel position
 *  das entradas devem ser igual ao dos pontos da matriz em que a entrada está conectada
 *
 *
 *  OBS: se for rodado um evaluate enquanto a saida do componente não está conectada a nada, ao conectar deve ser
 *  rodado o evaluate novamente para a entrada ser atualizada
 *
 */

int main() {
    LogicControl control;
    LogicComponent *orC = new OrComponent;
    LogicComponent *wir1 = new Wire(1);
    LogicComponent *wir2 = new Wire(1);


    control.setInputValue(0, false);
    control.setInputValue(3, true);

    control.addComponent(wir1);
    control.addComponent(wir2);
    control.addComponent(orC);

    control.connectWireInToArr(wir1,0);
    control.connectWireOutToMat(wir1, {0,1});

    control.connectWireInToArr(wir2,3);
    control.connectWireOutToMat(wir2, {0,2});

    control.connectInputToMat(orC, 0, {0,1});
    control.connectInputToMat(orC, 1, {0,2});

    control.connectOutputToArr(orC, 0);

    control.evaluateWires();

    orC->updateInputs();

    control.evaluate();

    std::cout<< orC->getOutConnection()->getValue();

    delete orC;
    delete wir1;
    delete wir2;

}