#include "commandqueue.h"

CommandQueue::CommandQueue(std::vector<Command*> commands){
    this->commands = commands;
}

CommandQueue* CommandQueue::Create(std::vector<Command*> commands){
    return new CommandQueue(commands);
}

void CommandQueue::execute(){
    std::vector<Command*>::iterator it;

    for(it = commands.begin(); it != commands.end(); it++){
        (*it)->execute();
    }
}
