#include <QDesktopWidget>
#include <QDockWidget>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include "Application.hpp"
#include "StatusConsoleDock.hpp"
#include "Game.hpp"
#include "ControlPanel.hpp"

Application::Application(QWidget *parent) : QMainWindow(parent) {
    resize(600,600);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
    setStyleSheet("QMainWindow {background : url(:/resources/background.png);}"
                  "QMainWindow::separator { 20px}");


    QFrame *frame = new QFrame(this);
    frame->setStyleSheet("QTextEdit { border-image: url(:/resources/border.png); border-width : 30px; color : white; }");
    frame->setFrameStyle(QFrame::Box);
    central_widget_layout = new QVBoxLayout;
    frame->setLayout(central_widget_layout);
    game = new Game(frame);
    central_widget_layout->addWidget(game->getCanvas());
    game->start();

    control_panel = new ControlPanel();

    right_dock = new QDockWidget(this);
    right_dock->setMinimumWidth(250);
    right_dock->setStyleSheet("QTextEdit { border-image: url(:/resources/border.png); border-width : 20px; color : white}");
    right_dock->setWidget(control_panel);
    right_dock->setTitleBarWidget(new QWidget(right_dock));

    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);

    console_dock = new StatusConsoleDock( this);
    console_dock->setTitleBarWidget(new QWidget(console_dock));
    console_dock->setMinimumHeight(200);

    tool_bar = new QToolBar(this);
    tool_bar->setMovable(false);
    tool_bar->addAction("One");
    tool_bar->addAction("Two");

    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, right_dock);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, tool_bar);


    setCentralWidget(frame);
}

Application::~Application() {
    game->stop();
    delete this->game;
}
