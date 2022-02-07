#include <QDesktopWidget>
#include <QDockWidget>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QMenuBar>
#include <iostream>
#include <QResizeEvent>
#include "Application.hpp"
#include "ui/StatusConsoleDock.hpp"
#include "game/Game.hpp"
#include "ui/control_panel/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"

Application::Application(QWidget *parent) : QMainWindow(parent) {
    this->resize(1280, 720);
    setStyleSheet("QMainWindow {background : lightblue;}");

//    central_widget_frame = new QWidget(this);
//    central_widget_layout = new QBoxLayout(QBoxLayout::TopToBottom);
//    central_widget_layout->setContentsMargins(-10,-10,-10,-10);
//    central_widget_frame->setLayout(central_widget_layout);
    game = new Game(this);
//    central_widget_layout->addWidget(game->getCanvas());
    game->start();

    control_panel_dock = new ControlPanelDock(this);
    console_dock = new StatusConsoleDock( this);
    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);
    setCorner(Qt::Corner::BottomLeftCorner, Qt::DockWidgetArea::LeftDockWidgetArea);

    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, control_panel_dock);

    // Connect UI Buttons.

//    connect(((ControlPanel*)control_panel_dock->widget())->getUseButton(), &InventoryButton::clicked,
//            (StatusConsole*)console_dock->widget(), &StatusConsole::print_hello);

    setCentralWidget(game->getCanvas());
}

Application::~Application() {
    game->stop();
    delete this->game;
}

void Application::print_hello() {
    if (console_dock->widget() != nullptr) {
        auto *console = (StatusConsole*)console_dock->widget();
        console->append_text("Hello, World!");
    }
}

void Application::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

void Application::createMenuBar() {
    auto *menu_bar = new QMenuBar(this);

    auto resolutions_menu = new QMenu("Resolutions", this);
    resolutions_menu->addAction("Fullscreen", [=]() -> void {
        this->showFullScreen();
    });
    resolutions_menu->addAction("1920x1080", [=]() -> void {
        this->resize(1920, 1080);
        this->showNormal();
    });
    resolutions_menu->addAction("1280x720", [=]() -> void {
        this->resize(1280, 720);
        this->showNormal();
    });
    resolutions_menu->addAction("640x360", [=]() -> void {
        this->resize(640, 360);
        this->showNormal();
    });
    resolutions_menu->addAction("1024x768", [=]() -> void {
        this->resize(1024, 768);
        this->showNormal();
    });
    menu_bar->addMenu(resolutions_menu);
    setMenuBar(menu_bar);
}
