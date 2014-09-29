#ifndef PORTCONNECTOR_H
#define PORTCONNECTOR_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <QDebug>

#include "console.h"

class PortConnector
{
public:
    PortConnector(Console*);

    void connect();
    void disconnect();
    void write(std::string);
    void execute(std::string);
    void execute(std::string,std::string);

private:
    QSerialPort *serial;
    Console *console;
};

#endif // PORTCONNECTOR_H
