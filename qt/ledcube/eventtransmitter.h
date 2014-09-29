#ifndef EVENTTRANSMITTER_H
#define EVENTTRANSMITTER_H

#include <QWidget>
#include <QDebug>
#include <map>
#include "command.h"

class EventTransmitter : public QWidget
{
    Q_OBJECT

public:
    explicit EventTransmitter(QWidget *parent = 0);
    void setCommands(std::map<std::string,Command*>);
    ~EventTransmitter();

public slots:
    void ExecuteCommand(std::string);

signals:
    void SendCommand(std::string);

private:
    std::map<std::string,Command*> commands;
};

#endif // EVENTTRANSMITTER_H
