#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->uiRegions["console"] = ui->consoleContainer;
    this->uiRegions["catalog"] = ui->catalogContainer;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCommands(std::map<std::string,Command*> commands){
    this->commands = commands;
}

void MainWindow::addWidgetToUiRegion(std::string uiregion,QWidget* widget){
    this->uiRegions[uiregion]->addWidget(widget);
}

//void MainWindow::LaunchCubeEffect(){

    //QListWidgetItem *current = this->ui->effectList->currentItem();

    //if(current != NULL){
        //emit SendCommand("Lunch:" + current->text().toStdString());
    //}
//}

void MainWindow::ExecuteCommand(std::string action){
    this->commands[action]->execute();
}

