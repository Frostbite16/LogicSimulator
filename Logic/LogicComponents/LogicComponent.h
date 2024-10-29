#ifndef LOGICCOMPONENT_H
#define LOGICCOMPONENT_H

#include<vector>

using namespace std;

class LogicComponent {
    vector<bool> inputs;
    bool output;
protected:
    void addNewInput(bool value);
    void setOutput(bool value) {
        output = value;
    }
    _Bit_reference getInput(size_t index);
public:
    LogicComponent();
    virtual void addAllInputs(size_t size) = 0;
    virtual void changeInput(bool value, size_t index) = 0;
    virtual bool evaluate() = 0;

    size_t getSizeOfInputs();
    bool getOutput() const;

};

#endif //LOGICCOMPONENT_H
