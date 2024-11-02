#include "LogicComponent.h"
#include <stdexcept>

LogicComponent::LogicComponent() {
    numInputs = 2;
    initializeComponent();
    outConnection = nullptr;
    savedValue = false;
    componentID = 0;
}

LogicComponent::LogicComponent(size_t numInputs): numInputs(numInputs) {
    initializeComponent();
    outConnection = nullptr;
    savedValue = false;
    componentID = 0;
}

void LogicComponent::addNewInConnection(LogicPoint* local) {
    inConnections.push_back(local);
}

void LogicComponent::addNewOutConnection(LogicPoint* local){
    outConnection = local;
}

LogicPoint*& LogicComponent::getInConnection(size_t index){
    if(index < numInputs)
        return inConnections[index];
    throw std::out_of_range("index out of range");
}

LogicPoint*& LogicComponent::getOutConnection() {
    return outConnection;
}

void LogicComponent::setOutValue(const bool value){
    if(outConnection!=nullptr)
        outConnection->getValue() = value;
    savedValue = value;
}

void LogicComponent::alterComponentID(short componentID) {
    this->componentID = componentID;
}


void LogicComponent::initializeComponent() {
    for(int i = 0; i < numInputs; i++){
        addNewInConnection(new LogicPoint());
    }
}

void LogicComponent::connectInput(LogicPoint *local, const size_t index){
    inConnections[index] = local;
}

void LogicComponent::connectOutput(LogicPoint *local){
    local->changeValue(savedValue);
    outConnection = local;
}


bool LogicComponent::getOutValue() const{
    return outConnection->getValue();
}

bool LogicComponent::searchInConnection(const LogicPoint* local) {
    if(find(inConnections.begin(), inConnections.end(), local) != inConnections.end())
        return true;
    return false;
}

size_t LogicComponent::getInConnectionSize() const{

    return inConnections.size();
}

LogicComponent::~LogicComponent() {
    for(const auto & inConnection : inConnections) {
        delete inConnection;
    }
}