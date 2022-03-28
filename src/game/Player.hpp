#ifndef SPORK_PLAYER_H
#define SPORK_PLAYER_H
#include "Entity.hpp"

class Player : public Entity {
public:
    Player(QPixmap image);

    QPoint getMoveDirection();
    void setMoveDirection(QPoint p);
    void setMoveDirection(int x, int y);

private:
    QPoint move_direction;
};


#endif //SPORK_PLAYER_H
