#include "GameScene.hpp"

GameScene::GameScene(QWidget *parent) : QGraphicsScene(parent) {
    setSceneRect(sceneRect().x(),sceneRect().y(), 100,100);
}
