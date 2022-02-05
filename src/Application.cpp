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
#include "Game.hpp"
#include "ui/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"

Application::Application(QWidget *parent) : QMainWindow(parent) {
    setStyleSheet("QMainWindow {background : lightblue;}"
                  "QMainWindow::separator {20px}");

    central_widget_frame = new QWidget(this);
    central_widget_layout = new QBoxLayout(QBoxLayout::TopToBottom);
    central_widget_layout->setContentsMargins(30,30,30,30);
    central_widget_frame->setLayout(central_widget_layout);
    game = new Game(central_widget_frame);
    central_widget_layout->addWidget(game->getCanvas());
    game->start();

    control_panel_dock = new ControlPanelDock(this);
    console_dock = new StatusConsoleDock( this);
    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);

    auto *menu_bar = new QMenuBar(this);

    QAction *newAct = new QAction(tr("&Test"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Test print"));
    connect(newAct, &QAction::triggered, this, &Application::print_hello);
    menu_bar->addAction(newAct);

    QMenu *resolutions_menu = new QMenu("Resolutions", this);
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
    menu_bar->addMenu(resolutions_menu);
    setMenuBar(menu_bar);

    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, control_panel_dock);
    setCentralWidget(central_widget_frame);
}

Application::~Application() {
    game->stop();
    delete this->game;
}

void Application::print_hello() {
    std::cout << "Hello, World!" << std::endl;
}

void Application::resizeEvent(QResizeEvent *event) {
    // std::cout << control_panel_dock->widget()->height() + control_panel_dock->titleBarWidget()->height() << " " << event->size().height() << std::endl;
    // std::cout << menuBar()->size().height() << std::endl;

    int vertical_space_left = event->size().height();
    //control_panel_dock->widget()->setSize(event->size().width() / 2, vertical_space_left);

    // int control_panel_height = control_panel_dock->widget()->height();
    // int title_bar_height = control_panel_dock->titleBarWidget()->height();
    // double ratio =  (double)control_panel_height / (double)(control_panel_height + title_bar_height);
    // control_panel_dock->titleBarWidget()->setFixedSize(event->size().width() / 2, abs((ratio - 1)) * vertical_space_left);

//    control_panel_dock->titleBarWidget()->setFixedSize(
//            control_panel_dock->widget()->width(), 16 * 2);

//    console_dock->widget()->setFixedSize(event->size().width() / 2, event->size().height() / 2);
//    console_dock->titleBarWidget()->setFixedSize(
//            console_dock->widget()->width(), 16 * 2);

    QWidget::resizeEvent(event);
}