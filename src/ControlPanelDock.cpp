//
// Created by dawids on 28/01/2022.
//

#include <QWidget>
#include "ControlPanelDock.hpp"

ControlPanelDock::ControlPanelDock(QWidget *parent) {
    control_panel = new ControlPanel(this);
    title_bar = new DockTitleBar("Control Panel Dock", this, "./resources/control_panel_title.png");

    QSizePolicy size_policy = QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    setSizePolicy(size_policy);

    setTitleBarWidget(title_bar);
    setWidget(control_panel);
}
