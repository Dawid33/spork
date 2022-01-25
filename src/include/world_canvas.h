#ifndef WORLD_CANVAS_H
#define WORLD_CANVAS_H

#include <QTextEdit>
#include <QOpenGLWidget>

class WorldCanvas : public QOpenGLWidget {
public:
    explicit WorldCanvas(QWidget *parent = nullptr);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};


#endif //WORLD_CANVAS_H
