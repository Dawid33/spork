#include "GameCanvas.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include "Game.hpp"

GameCanvas::GameCanvas(QWidget *parent, Game *game) : QOpenGLWidget(parent) {
    this->game = reinterpret_cast<Game *>(parent);
}

void GameCanvas::initializeGL() {
}

void GameCanvas::paintGL() {
}

void GameCanvas::resizeGL(int width, int height) {
}
