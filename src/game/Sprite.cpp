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

void Sprite::move(QPoint p) {
    move(p.x(),p.y());
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

int Sprite::getImageId() {
    return image_id;
}

void Sprite::setImageId(int id) {
    image_id = id;
}

QPixmap Sprite::getPixmap() {
    return this->graphics_item->pixmap();
}

void Sprite::setPosition(QPoint p) {
    position = p;
}

