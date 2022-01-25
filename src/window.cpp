#include <QDesktopWidget>
#include <QDockWidget>
#include "window.h"
#include "world_canvas.h"
#include "status_bar.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

    this->canvas = new WorldCanvas(this);
    this->status_bar = new StatusBar("Status Bar", this);
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
    
    setCentralWidget(this->canvas);
}