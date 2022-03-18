#include "Sprite.hpp"

Sprite::Sprite(QPixmap image){
    graphics_item = new QGraphicsPixmapItem(image);
}

void Sprite::setPosition(int x, int y) {
    position.setX(x * 16);
    position.setY(y * 16);
}

void Sprite::move(int x, int y) {
    position.setX(position.x() + x * 16);
    position.setY(position.y() + -y * 16);
}

void Sprite::updateGraphics() {
    graphics_item->setPos(position);
}

QGraphicsPixmapItem *Sprite::graphicsItem() {
    return graphics_item;
}

QPoint Sprite::getPosition() {
    return position;
}
