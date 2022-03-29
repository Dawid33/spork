//
// Created by dawids on 29/03/2022.
//

#include "Wizard.hpp"
#include <QDebug>

void Wizard::updateGraphics() {
    if (!is_alive) {
        graphics_item->setPixmap(QPixmap());
    }
    Sprite::updateGraphics();
}

Wizard::Wizard(QPixmap pixmap) : Entity(pixmap) {

}
