#include <QPainter>
#include "DockTitleBar.hpp"
#include "Globals.h"

DockTitleBar::DockTitleBar(QString title, QWidget *parent, const char* image_path) : QLabel(title, parent) {
    background_image = QPixmap(image_path);
    setFixedHeight(background_image.height() * ui_scale);
}

void DockTitleBar::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), background_image);}