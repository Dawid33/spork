#include "GameView.hpp"
#include "Game.hpp"
#include <QDebug>

GameView::GameView(Game *game, GameScene *scene) : QGraphicsView((QGraphicsScene*)scene){
    this->game = game;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    connect(game, &Game::updateScene, this, &GameView::updateScene);
    connect(game, &Game::moveViewport, this, &GameView::moveViewport);

    for(Sprite* s : game->tiles) {
        s->updateGraphics();
        scene->addItem(s->graphicsItem());
    }
    for (Entity* s : game->entities) {
        s->updateGraphics();
        scene->addItem(s->graphicsItem());
    }

    int x = game->player->getPosition().x();
    int y = game->player->getPosition().x();
    moveViewport(x, y);
}

void GameView::keyPressEvent(QKeyEvent *event) {
    game->keyPressEvent(event);
}

void GameView::updateScene() {
    for (Entity* s : game->entities) {
        s->updateGraphics();
    }
}

void GameView::moveViewport(int x, int y) {
    centerOn(x, y);
    scene()->setSceneRect(x - scene()->width() / 2, y - scene()->height() / 2, scene()->width(), scene()->height());
}
