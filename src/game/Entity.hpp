#ifndef SPORK_ENTITY_H
#define SPORK_ENTITY_H
#include "Sprite.hpp"

class Entity : public Sprite {
public:
    explicit Entity(QPixmap image);
};


#endif //SPORK_ENTITY_H
