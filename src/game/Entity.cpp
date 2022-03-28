#include "Entity.hpp"

Entity::Entity() : Sprite(QPixmap()) {
    on_enter = QString("");
}

Entity::Entity(QPixmap p) : Sprite(p) {
    on_enter = QString("");
}

QRect Entity::getCollisionRectangle() {
    return collision_rectangle;
}

void Entity::setCollisionRectable(QRect value) {
    collision_rectangle = value;
}

QString Entity::getOnEnterString() {
    return on_enter;
}

void Entity::setOnEnterString(const QString &value) {
    on_enter = value;
}

Entity::~Entity() {
}
