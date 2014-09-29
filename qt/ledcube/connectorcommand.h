#ifndef CONNECTORCOMMAND_H
#define CONNECTORCOMMAND_H

#include <QDebug>

#include "command.h"
#include "portconnector.h"

class ConnectorCommand : public Command
{
public:
    ConnectorCommand(PortConnector*,std::string);
    ConnectorCommand(PortConnector*,std::string,std::string);
    static ConnectorCommand* Create(PortConnector*,std::string);
    static ConnectorCommand* Create(PortConnector*,std::string,std::string);
    void execute();

private:
    PortConnector* connector;
    std::string method;
    std::string data;
};

#endif // CONNECTORCOMMAND_H
