#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDebug>
#include "command.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setCommands(std::map<std::string,Command*>);
    void addWidgetToUiRegion(std::string,QWidget*);

private:
    Ui::MainWindow *ui;
    std::map<std::string,Command*> commands;
    std::map<std::string,QLayout*> uiRegions;

public slots:
    void ExecuteCommand(std::string action);

signals:
    void SendCommand(std::string);
};

#endif // MAINWINDOW_H
