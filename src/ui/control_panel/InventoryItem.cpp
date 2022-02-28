#include "InventoryItem.hpp"

InventoryItem::InventoryItem(QString name, QPixmap background) : QTableWidgetItem() {
    background_image = background;
    this->name = name;
}

QString InventoryItem::getName() {
    return name;
}

QPixmap &InventoryItem::getBackground() {
    return background_image;
}
