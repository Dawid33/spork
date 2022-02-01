#include <QPainter>
#include "ControlPanel.hpp"
#include "Globals.h"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border = QPixmap("./resources/control_panel_border.png");
    setMinimumHeight(border.height() * ui_scale);
    setMinimumWidth(border.width() * ui_scale);
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}