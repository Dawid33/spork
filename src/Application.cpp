#include <QDesktopWidget>
#include <QDockWidget>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include "Application.hpp"
#include "StatusConsoleDock.hpp"
#include "Game.hpp"
#include "ControlPanel.hpp"
#include "ControlPanelDock.hpp"

Application::Application(QWidget *parent) : QMainWindow(parent) {
    resize(600,600);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
    setStyleSheet("QMainWindow {background : lightblue;}"
                  "QMainWindow::separator { 20px}");

    central_widget_frame = new QWidget(this);
    central_widget_layout = new QBoxLayout(QBoxLayout::TopToBottom);
    central_widget_layout->setContentsMargins(30,30,30,30);
    central_widget_frame->setLayout(central_widget_layout);
    game = new Game(central_widget_frame);
    central_widget_layout->addWidget(game->getCanvas());
    game->start();

    control_panel_dock = new ControlPanelDock(this);

    console_dock = new StatusConsoleDock( this);
    console_dock->show();

    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);

    tool_bar = new QToolBar(this);
    tool_bar->setMovable(false);
    tool_bar->addAction("One");
    tool_bar->addAction("Two");

    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, control_panel_dock);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, tool_bar);


    setCentralWidget(central_widget_frame);
}

Application::~Application() {
    game->stop();
    delete this->game;
}
