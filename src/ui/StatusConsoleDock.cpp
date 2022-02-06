#include "StatusConsoleDock.hpp"
#include <QResizeEvent>
#include <iostream>
#include <QSizePolicy>

StatusConsoleDock::StatusConsoleDock(QWidget *parent) : QDockWidget(parent) {
    console = new StatusConsole(this);
//    title_bar = new DockTitleBar("Status Console Dock", this, "./resources/bottom_title.png");
//    setTitleBarWidget(title_bar);
    setWidget(console);
}

void StatusConsoleDock::resizeEvent(QResizeEvent *event) {
    //title_bar->background_image = title_bar->background_image_base.scaled(event->size().width(), event->size().height() * 0.3, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::FastTransformation);
    //title_bar->setFixedHeight(title_bar->background_image.height());

    console->border = console->border_base.scaled(event->size().width(), event->size().height(), Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::FastTransformation);
    console->setMinimumHeight(console->border.size().height());
}