#include "world_canvas.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

WorldCanvas::WorldCanvas(QWidget *parent) : QOpenGLWidget(parent) {
    
}

void WorldCanvas::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void WorldCanvas::resizeGL(int width, int height) {
    // Update projection matrix and other size related settings:
    //m_projection.setToIdentity();
    //m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
}

void WorldCanvas::paintGL() {
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