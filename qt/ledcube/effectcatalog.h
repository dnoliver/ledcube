#ifndef EFFECTCATALOG_H
#define EFFECTCATALOG_H

#include <QWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <map>
#include "command.h"

namespace Ui {
class EffectCatalog;
}

class EffectCatalog : public QWidget
{
    Q_OBJECT

public:
    explicit EffectCatalog(QWidget *parent = 0);
    ~EffectCatalog();

    void addWidgetToUiRegion(std::string,QListWidgetItem*);
    void setCommands(std::map<std::string,Command*>);
    void executeCommand(std::string);
    void execute(std::string);

private:
    Ui::EffectCatalog *ui;
    std::map<std::string,Command*> commands;

private slots:
    void LunchEffect();
    void Connect();
    void Stop();
};

#endif // EFFECTCATALOG_H
