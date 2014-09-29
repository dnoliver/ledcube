#include "portconnector.h"

PortConnector::PortConnector(Console* console)
{
    this->serial = new QSerialPort();
    this->console = console;
}

void PortConnector::execute(std::string method){
    if(method == "connect") this->connect();
    else if(method == "disconnect") this->disconnect();
    else qDebug() << "unknown metod" + QString::fromStdString(method);
}

void PortConnector::execute(std::string method, std::string data){
    if(method == "write") this->write(data);
    else qDebug() << "unknown metod" + QString::fromStdString(method);
}

/*
 * taken from
 * http://stackoverflow.com/questions/24415243/connect-arduino-with-qt
 */
void PortConnector::connect(){
    /*
     * Some info
     */
    if(serial->isOpen()){
        return;
    }

    std::string port = "/dev/ttyACM0";
    console->insertPlainText(QString::fromStdString("\nconnecting to port " + port + "\n"));

    serial->setPortName(QString::fromStdString(port));
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->isOpen() && serial->isWritable()){
        QSerialPortInfo info(QString::fromStdString(port));

        console->insertPlainText(QString::fromStdString("connection stablished\n"));
        console->insertPlainText(info.portName());
        console->insertPlainText(info.manufacturer());
    }
    else {
        console->insertPlainText(QString::fromStdString("connection error\n"));
        console->insertPlainText(serial->errorString());
    }
}

void PortConnector::disconnect(){
    if(serial->isOpen()){
        console->insertPlainText(QString::fromStdString("\nclosing port connection\n"));
        serial->close();
    }
}

void PortConnector::write(std::string data){
    if(serial->isOpen() && serial->isWritable()){
        serial->write(data.c_str());
    }
}

