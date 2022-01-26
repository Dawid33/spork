#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>

class Game;
class GameCanvas : public QOpenGLWidget {
public:
    explicit GameCanvas(QWidget *parent, Game *game);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
private:
    Game* game = nullptr;
};


#endif //WORLD_CANVAS_H
