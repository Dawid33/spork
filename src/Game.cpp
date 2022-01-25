#include "Game.hpp"
#include <iostream>

Game::Game(QWidget *parent) {
    this->canvas = new GameCanvas(parent);
}

Game::~Game() {
    delete this->canvas;
}

GameCanvas *Game::getCanvas() {
    return this->canvas;
}

void Game::run() {
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
