//
// Created by dawids on 24/01/2022.
//

#include <QDesktopWidget>
#include "window.h"

Window::Window(QWidget *parent) :
        QMainWindow(parent) {
    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

    button = new QPushButton("Hello World", this);
    setCentralWidget(button);
}