#ifndef CONSOLECOMMAND_H
#define CONSOLECOMMAND_H

#include <QString>
#include "command.h"
#include "console.h"

class ConsoleCommand : public Command
{
public:
    ConsoleCommand(Console*,std::string);
    static ConsoleCommand* Create(Console*,std::string);
    void execute();

private:
    Console* console;
    std::string message;
};

#endif // LOGCOMMAND_H
