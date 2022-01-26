#include <QImage>
#include <iostream>
#include <QOpenGLTexture>
#include "Game.hpp"

Game::Game(QWidget *parent) : QThread(parent) {
    this->canvas = new GameCanvas(parent, this);
}

Game::~Game() {
    delete this->canvas;
}

GameCanvas *Game::getCanvas() {
    return this->canvas;
}

void Game::run() {
    this->load();

    while(this->isRunning) {
        if (this->isPaused){
            continue;
        }

    }
}

void Game::stop() {
    this->isRunning = false;
    this->wait();
}

void Game::load() {
}
