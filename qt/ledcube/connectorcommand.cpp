#include "connectorcommand.h"

ConnectorCommand::ConnectorCommand(PortConnector* connector, std::string method){
    this->connector = connector;
    this->method = method;
}


ConnectorCommand::ConnectorCommand(PortConnector* connector, std::string method, std::string data){
    this->connector = connector;
    this->method = method;
    this->data = data;
}

ConnectorCommand* ConnectorCommand::Create(PortConnector* connector, std::string method){
    return new ConnectorCommand(connector,method);
}

ConnectorCommand* ConnectorCommand::Create(PortConnector* connector, std::string method, std::string data){
    return new ConnectorCommand(connector,method,data);
}

void ConnectorCommand::execute(){
    if(this->data != ""){
        this->connector->execute(this->method,this->data);
    }
    else {
        this->connector->execute(this->method);
    }
}
