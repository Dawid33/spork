#include <QResizeEvent>
#include <QWidget>
#include <iostream>
#include "ControlPanelDock.hpp"

ControlPanelDock::ControlPanelDock(QWidget *parent) {
    control_panel = new ControlPanel(this);
    //title_bar = new DockTitleBar("Control Panel Dock", this, "./resources/right_title.png");

    //setTitleBarWidget(title_bar);
    setWidget(control_panel);
}

void ControlPanelDock::resizeEvent(QResizeEvent *event) {
    //title_bar->background_image = title_bar->background_image_base.scaled(event->size().width(), event->size().height() * 0.2, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::FastTransformation);
    //title_bar->setFixedHeight(title_bar->background_image.height());

    control_panel->border = control_panel->border_base.scaledToHeight(event->size().height(), Qt::TransformationMode::FastTransformation);
    control_panel->setFixedWidth(control_panel->border.size().width());
}