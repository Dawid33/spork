#include <QDesktopWidget>
#include <QDockWidget>
#include "Application.hpp"
#include "StatusConsole.hpp"
#include "Game.hpp"

Application::Application(QWidget *parent) : QMainWindow(parent) {
    resize(600,600);
    //resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

    this->game = new Game(this);
    this->game->start();
    this->status_bar = new StatusConsole("Status Bar", this);
    this->right = new QDockWidget("Right", this);
    this->setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);

    this->status_bar->setMinimumHeight(200);
    this->right->setMinimumWidth(250);

    this->tool_bar = new QToolBar(this);
    this->tool_bar->setMovable(false);
    this->tool_bar->addAction("One");
    this->tool_bar->addAction("Two");

    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, this->status_bar);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, this->right);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, this->tool_bar);
    
    setCentralWidget(this->game->getCanvas());
}

Application::~Application() {
    game->stop();
    delete this->game;
}