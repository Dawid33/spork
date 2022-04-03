#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <QFrame>
#include <QGraphicsScene>
#include "game/Sprite.hpp"

class Game;
class GameScene : public QGraphicsScene {
public:
    explicit GameScene(QWidget *parent);
};


#endif //WORLD_CANVAS_H
