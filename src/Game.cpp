#include <QImage>
#include <iostream>
#include <QOpenGLTexture>
#include "Game.hpp"
#include <QTimer>
#include <QConstOverload>
#include <QVBoxLayout>

Game::Game(QWidget *parent) : QThread(parent) {
    paint_timer = new QTimer(this);
    paint_timer->setInterval(10);
    connect(paint_timer, &QTimer::timeout, this, &Game::paintCanvasAtNextUpdate);
    paint_timer->start();

    canvas = new GameCanvas(parent, this);
}

Game::~Game() {
    delete this->paint_timer;
    delete this->canvas;
}

GameCanvas *Game::getCanvas() {
    return canvas;
}

void Game::run() {
//    while(this->isRunning) {
//        if (this->isPaused){
//            continue;
//        }
//        update();
//    }
}

void Game::stop() {
    this->isRunning = false;
    this->wait();
}

void Game::update() {
    if (shouldPaintCanvas) {
        canvas->update();
        shouldPaintCanvas = false;
    }
}

void Game::paintCanvasAtNextUpdate() {
    shouldPaintCanvas = true;
}
