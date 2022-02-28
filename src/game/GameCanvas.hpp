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

class Game;
class GameCanvas : public QGraphicsScene {
public:
    explicit GameCanvas(QWidget *parent, Game *game);
protected:
private:
    Game* game = nullptr;
};


#endif //WORLD_CANVAS_H
