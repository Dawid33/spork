#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include "ControlPanel.hpp"
#include "../Globals.hpp"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/inventory_old.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}
