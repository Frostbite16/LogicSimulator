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
    virtual bool evaluate() = 0;
    
    void addAllInputs(size_t size);
    void changeInput(bool value, size_t index);
    

    size_t getSizeOfInputs();
    bool getOutput() const;

};

#endif //LOGICCOMPONENT_H
