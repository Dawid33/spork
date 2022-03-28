#ifndef SPORK_ENTITY_H
#define SPORK_ENTITY_H
#include "Sprite.hpp"

class Entity : public Sprite {
public:
    explicit Entity();
    explicit Entity(QPixmap pixmap);
    ~Entity();

    QRect getCollisionRectangle();
    void setCollisionRectable(QRect rect);

    QString getOnEnterString();
    void setOnEnterString(const QString &value);

    bool has_entered = false;
private:
    QRect collision_rectangle;
    QString on_enter = QString("");
};


#endif //SPORK_ENTITY_H
