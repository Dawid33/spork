#include "Player.hpp"
#include "Game.hpp"

Player::Player(QPixmap image) : Entity(image) {

}

QPoint Player::getMoveDirection() {
    return move_direction;
}

void Player::setMoveDirection(QPoint p) {
    move_direction = p;
}

void Player::setMoveDirection(int x, int y) {
    move_direction = QPoint(x,y);
}
