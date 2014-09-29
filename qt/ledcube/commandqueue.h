#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <vector>
#include "command.h"

class CommandQueue : public Command
{
public:
    CommandQueue(std::vector<Command*>);
    static CommandQueue* Create(std::vector<Command*>);

    void execute();

private:
    std::vector<Command*> commands;
};

#endif // COMMANDQUEUE_H
