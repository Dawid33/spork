#include <QAbstractButton>
#include <QPainter>
#include "InventoryButton.hpp"

InventoryButton::InventoryButton(QWidget *parent, QPixmap background) : QAbstractButton(parent) {
    background_image = background;
}

void InventoryButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (isDown()) {
        auto tint = QColor(133,76,48);
        QPixmap img(background_image);
        QPixmap mask(background_image);

        QPainter p;
        p.begin(&mask);
        p.setCompositionMode(QPainter::CompositionMode_SourceIn);
        p.fillRect(rect(), tint);
        p.end();

        p.begin(&img);
        p.setCompositionMode(QPainter::CompositionMode_Overlay);
        p.drawPixmap(0,0, mask);
        p.end();

        painter.drawPixmap(0,0, width(), height(), img);
    } else {
        painter.drawPixmap(0,0,this->width(), this->height(), background_image);
    }
}

void InventoryButton::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}