#include <QApplication>
#include <QDebug>
#include <QListWidgetItem>
#include <map>
#include <vector>

#include "mainwindow.h"
#include "console.h"
#include "effectcatalog.h"

#include "cubeeffect.h"

#include "command.h"
#include "consolecommand.h"
#include "connectorcommand.h"
#include "commandqueue.h"

#include "portconnector.h"
#include "eventtransmitter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Console *console = new Console;
    EffectCatalog *catalog = new EffectCatalog;
    PortConnector *connector = new PortConnector(console);

    CubeEffect *shutdown = CubeEffect::Create(CubeEffect::ShutDownEffect);
    CubeEffect *blink = CubeEffect::Create(CubeEffect::BlinkEffect);
    CubeEffect *plainboing = CubeEffect::Create(CubeEffect::PlainBoingEffect);
    CubeEffect *rain = CubeEffect::Create(CubeEffect::RainEffect);
    CubeEffect *randomfiller = CubeEffect::Create(CubeEffect::RandomFillerEffect);
    CubeEffect *boxsiderandsend = CubeEffect::Create(CubeEffect::BoxsideRandsend);
    CubeEffect *preview = CubeEffect::Create(CubeEffect::PreviewEffect);

    std::map<std::string,Command*> catalogCommands;

    std::vector<Command*> connectCommand;
    std::vector<Command*> stopCommand;
    std::vector<Command*> launchShutDownCommand;
    std::vector<Command*> launchBlinkCommand;
    std::vector<Command*> launchPlainboingCommand;
    std::vector<Command*> launchRainCommand;
    std::vector<Command*> launchRandomfillerCommand;
    std::vector<Command*> launchBoxsiderandsendCommand;
    std::vector<Command*> launchPreviewCommand;

    // add console and catalog to main window
    w.addWidgetToUiRegion("console",console);
    w.addWidgetToUiRegion("catalog",catalog);

    // add effects widgets to catalog
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(shutdown->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(blink->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(plainboing->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(rain->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(randomfiller->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(boxsiderandsend->getName())));
    catalog->addWidgetToUiRegion("list",new QListWidgetItem(QString::fromStdString(preview->getName())));

    // set effects luncher commands
    launchShutDownCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + shutdown->getName()));
    launchShutDownCommand.push_back(ConnectorCommand::Create(connector,"write",shutdown->getCode()));

    launchBlinkCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + blink->getName()));
    launchBlinkCommand.push_back(ConnectorCommand::Create(connector,"write",blink->getCode()));

    launchPlainboingCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + plainboing->getName()));
    launchPlainboingCommand.push_back(ConnectorCommand::Create(connector,"write",plainboing->getCode()));

    launchRainCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + rain->getName()));
    launchRainCommand.push_back(ConnectorCommand::Create(connector,"write",rain->getCode()));

    launchRandomfillerCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + randomfiller->getName()));
    launchRandomfillerCommand.push_back(ConnectorCommand::Create(connector,"write",randomfiller->getCode()));

    launchBoxsiderandsendCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + boxsiderandsend->getName()));
    launchBoxsiderandsendCommand.push_back(ConnectorCommand::Create(connector,"write",boxsiderandsend->getCode()));

    launchPreviewCommand.push_back(ConsoleCommand::Create(console,"effect lunched: " + preview->getName()));
    launchPreviewCommand.push_back(ConnectorCommand::Create(connector,"write",preview->getCode()));

    // set up connection commands
    connectCommand.push_back(ConnectorCommand::Create(connector,"connect"));
    stopCommand.push_back(ConnectorCommand::Create(connector,"disconnect"));

    // set catalog commands
    catalogCommands["Launch:"+shutdown->getName()] = CommandQueue::Create(launchShutDownCommand);
    catalogCommands["Launch:"+blink->getName()] = CommandQueue::Create(launchBlinkCommand);
    catalogCommands["Launch:"+plainboing->getName()] = CommandQueue::Create(launchPlainboingCommand);
    catalogCommands["Launch:"+rain->getName()] = CommandQueue::Create(launchRainCommand);
    catalogCommands["Launch:"+randomfiller->getName()] = CommandQueue::Create(launchRandomfillerCommand);
    catalogCommands["Launch:"+boxsiderandsend->getName()] = CommandQueue::Create(launchBoxsiderandsendCommand);
    catalogCommands["Launch:"+preview->getName()] = CommandQueue::Create(launchPreviewCommand);
    catalogCommands["Connect"] = CommandQueue::Create(connectCommand);
    catalogCommands["Stop"] = CommandQueue::Create(stopCommand);

    catalog->setCommands(catalogCommands);

    w.show();

    return a.exec();
}
