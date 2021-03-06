#include <QPainter>
#include <QResizeEvent>
#include "DockTitleBar.hpp"
#include "../Globals.hpp"

DockTitleBar::DockTitleBar(QString title, QWidget *parent, const char* image_path) : QLabel(title, parent) {
    background_image_base = QPixmap(image_path);
    background_image = background_image_base;
    setFixedHeight(background_image.height());
}

void DockTitleBar::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), background_image);
}