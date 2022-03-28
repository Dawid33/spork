#include <iostream>
#include <QDesktopWidget>
#include <QMenuBar>
#include <QDebug>
#include <QResizeEvent>
#include "MainWindow.hpp"
#include "ui/StatusConsoleDock.hpp"
#include "game/Game.hpp"
#include "ui/control_panel/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"
#include "ui/control_panel/InventoryItem.hpp"
#include <QTimer>
#include "Globals.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->resize(baseScreenWidth, baseScreenHeight);
    setStyleSheet("QMainWindow {background : lightblue;}");

    game = new Game(this);
    game->start();
    game_view = new GameView(game, new GameScene(this));

    QTransform trans;
    trans.scale(2.5,2.5);
    game_view->setTransform(trans, true);

    control_panel_dock = new ControlPanelDock(this);
    console_dock = new StatusConsoleDock( this);

    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);
    setCorner(Qt::Corner::BottomLeftCorner, Qt::DockWidgetArea::LeftDockWidgetArea);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, control_panel_dock);

    // Connect UI Buttons.
    connect(((ControlPanel*)control_panel_dock->widget())->useButton(), &InventoryButton::clicked,
            (StatusConsole*)console_dock->widget(), &StatusConsole::print_hello);
    connect(((ControlPanel*)control_panel_dock->widget()), &ControlPanel::selectedItem,
            this, &MainWindow::print_hello);

    setCentralWidget(game_view);
}

MainWindow::~MainWindow() {
    game->stop();
    delete this->game;
}

void MainWindow::print_hello(InventoryItem *item) {
    if (console_dock->widget() != nullptr && item != nullptr) {
        auto *console = (StatusConsole*)console_dock->widget();
        QString s = QString("Item : %1").arg(item->getName());
        console->append_text(s);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

//void MainWindow::createMenuBar() {
//    auto *menu_bar = new QMenuBar(this);
//
//    auto resolutions_menu = new QMenu("Resolutions", this);
//    resolutions_menu->addAction("Fullscreen", [=]() -> void {
//        this->showFullScreen();
//    });
//    resolutions_menu->addAction("1920x1080", [=]() -> void {
//        this->resize(1920, 1080);
//        this->showNormal();
//    });
//    resolutions_menu->addAction("1280x720", [=]() -> void {
//        this->resize(1280, 720);
//        this->showNormal();
//    });
//    resolutions_menu->addAction("640x360", [=]() -> void {
//        this->resize(640, 360);
//        this->showNormal();
//    });
//    resolutions_menu->addAction("1024x768", [=]() -> void {
//        this->resize(1024, 768);
//        this->showNormal();
//    });
//    menu_bar->addMenu(resolutions_menu);
//    setMenuBar(menu_bar);
//}
