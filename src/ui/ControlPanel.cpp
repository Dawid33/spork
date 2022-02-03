#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include "ControlPanel.hpp"
#include "../Globals.hpp"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border = QPixmap("./resources/control_panel_border.png");
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}


