#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QFrame>
#include <QGraphicsScene>
#include "game/Sprite.hpp"

class Game;
class GameScene : public QGraphicsScene {
public:
    explicit GameScene(QWidget *parent);
};


#endif //WORLD_CANVAS_H
