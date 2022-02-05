#include <QResizeEvent>
#include <QWidget>
#include "ControlPanelDock.hpp"

ControlPanelDock::ControlPanelDock(QWidget *parent) {
    control_panel = new ControlPanel(this);
    title_bar = new DockTitleBar("Control Panel Dock", this, "./resources/control_panel_title.png");

    setTitleBarWidget(title_bar);
    setWidget(control_panel);
}

void ControlPanelDock::resizeEvent(QResizeEvent *event) {
    title_bar->background_image = title_bar->background_image_base.scaled(event->size().width(), event->size().height() * 0.222, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::FastTransformation);
    title_bar->setFixedHeight(title_bar->background_image.height());

    control_panel->border = control_panel->border_base.scaledToHeight(event->size().height() * 0.888, Qt::TransformationMode::FastTransformation);
    control_panel->setFixedWidth(control_panel->border.width());
}