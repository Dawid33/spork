#include "GameCanvas.hpp"
#include "Game.hpp"
#include <iostream>
#include <QGraphicsView>

GameCanvas::GameCanvas(QWidget *parent, Game *game) : QGraphicsScene(parent) {
    this->game = game;
}

