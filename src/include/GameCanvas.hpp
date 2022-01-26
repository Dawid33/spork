#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>
#include <QOpenGLTexture>

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
    QOpenGLTexture *yellow{};
};


#endif //WORLD_CANVAS_H
