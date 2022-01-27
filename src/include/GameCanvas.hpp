#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
    GLint uniModel;
    std::chrono::time_point<std::chrono::system_clock> time_start;
};


#endif //WORLD_CANVAS_H
