#include "effectcatalog.h"
#include "ui_effectcatalog.h"

EffectCatalog::EffectCatalog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EffectCatalog)
{
    ui->setupUi(this);

    connect(ui->launchButton,SIGNAL(clicked()),this,SLOT(LunchEffect()));
    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(Connect()));
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(Stop()));
}

EffectCatalog::~EffectCatalog()
{
    delete ui;
}

void EffectCatalog::addWidgetToUiRegion(std::string uiregion,QListWidgetItem* item){
    if(uiregion == "list"){
        ui->effectsList->addItem(item);
    }
}

void EffectCatalog::setCommands(std::map<std::string,Command*> commands){
    this->commands = commands;
}

void EffectCatalog::executeCommand(std::string command){
    std::map<std::string,Command*>::iterator receiver = commands.find(command);

    if(receiver != this->commands.end()){
        receiver->second->execute();
    }
    else {
        qDebug() << "cannot execute" << QString::fromStdString(command);
    }
}

void EffectCatalog::LunchEffect(){
    QListWidgetItem *effect = ui->effectsList->currentItem();

    if(effect != NULL){
        std::string action = "Launch:" + effect->text().toStdString();
        this->executeCommand(action);
    }
}

void EffectCatalog::Connect(){
    this->executeCommand("Connect");
}

void EffectCatalog::Stop(){
    this->executeCommand("Stop");
}
