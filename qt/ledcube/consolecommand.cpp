#include "consolecommand.h"

ConsoleCommand::ConsoleCommand(Console* console,std::string message){
    this->console = console;
    this->message = message;
}

ConsoleCommand* ConsoleCommand::Create(Console* console,std::string message){
    return new ConsoleCommand(console,message);
}

void ConsoleCommand::execute(){
    this->console->appendPlainText(QString::fromStdString(this->message));
}
