#include "GameCanvas.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

GameCanvas::GameCanvas(QWidget *parent) : QOpenGLWidget(parent) {
    
}

void GameCanvas::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GameCanvas::resizeGL(int width, int height) {
}

void GameCanvas::paintGL() {
    // Draw the scene:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    
    glClear(GL_COLOR_BUFFER_BIT);
    /* Display a red square */
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}