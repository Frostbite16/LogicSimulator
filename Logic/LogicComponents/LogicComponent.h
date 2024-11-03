#ifndef LOGICCOMPONENT_H
#define LOGICCOMPONENT_H

#include<vector>
#include<algorithm>

#include "LogicPoint.h"


class LogicComponent: public LogicPoint{ // Representa qualquer componente na simulação
    std::vector<LogicPoint*> inConnections;
    LogicPoint* outConnection; // Ponteiro para o elemento conectado a saida
    bool savedValue;
    size_t numInputs;
    short componentID; // Diferencia o tipo de componente
protected:
    void addNewInConnection(LogicPoint* local); // Adiciona uma nova entrada lógica
    void addNewOutConnection(LogicPoint* local); // Adiciona uma nova saida lógica
    void setOutValue(bool value); //altera o valor da saida
    void alterComponentID(short componentID);

public:
    LogicComponent();
    LogicPoint*& getInConnection(size_t index);
    LogicPoint*& getOutConnection();
    explicit LogicComponent(size_t numImputs);
    void initializeComponent();
    void connectInput(LogicPoint* local, size_t index);
    void connectOutput(LogicPoint* local);
    bool getOutValue() const;
    bool searchInConnection(const LogicPoint* local);
    size_t getInConnectionSize() const;
    short getComponentID() const;
    virtual bool evaluate() = 0;
    virtual ~LogicComponent();
};

#endif //LOGICCOMPONENT_H
