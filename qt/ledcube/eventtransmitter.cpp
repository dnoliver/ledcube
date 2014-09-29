#include "eventtransmitter.h"

EventTransmitter::EventTransmitter(QWidget *parent) :
    QWidget(parent)
{

}

EventTransmitter::~EventTransmitter()
{

}

void EventTransmitter::setCommands(std::map<std::string,Command*> commands){
    this->commands = commands;
}

void EventTransmitter::ExecuteCommand(std::string action){
    this->commands[action]->execute();
}

