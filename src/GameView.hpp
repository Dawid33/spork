//
// Created by dawids on 18/03/2022.
//

#ifndef SPORK_GAMEVIEW_H
#define SPORK_GAMEVIEW_H
#include <QGraphicsView>
#include <QKeyEvent>
#include "GameScene.hpp"
#include "game/Player.hpp"

class GameView : public QGraphicsView {
public:
    GameView(Game *game, GameScene *scene);

protected:

    void keyPressEvent(QKeyEvent *event) override;

    Game* game = nullptr;
    GameScene *canvas;
public slots:
    void updateScene();
    void moveViewport(int x, int y);
};


#endif //SPORK_GAMEVIEW_H
