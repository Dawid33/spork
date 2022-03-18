#include <QImage>
#include <iostream>
#include <QOpenGLTexture>
#include <QVBoxLayout>
#include "Game.hpp"
#include <QTimer>
#include <QConstOverload>
#include <QFile>
#include <QDebug>
#include <QKeyEvent>

Game::Game(QWidget *parent) : QThread(parent) {
    game_tick_timer = new QTimer();
    game_tick_timer->setInterval(20);
    connect(game_tick_timer, &QTimer::timeout, this, &Game::setShouldUpdate);
    game_tick_timer->start();

    load_tiles("resources/raw.png", "resources/main.csv", tiles);
    load_entities("resources/main.csv", entities);
}

void Game::run() {
    while(this->isRunning) {
        if (this->isPaused){
            continue;
        }
        if (shouldUpdate) {
            shouldUpdate = false;
            update();
        }
    }
}

void Game::stop() {
    this->isRunning = false;
    this->wait();
}

void Game::update() {
    bool shouldUpdate = false;
    while(!key_events.empty()) {
        int key = key_events.front();
        if (key == Qt::Key_W) {
            player->move(0, 1);
            shouldUpdate = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_D) {
            player->move(1, 0);
            shouldUpdate = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_A) {
            player->move(-1, 0);
            shouldUpdate = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_S) {
            player->move(0, -1);
            shouldUpdate = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        }
        key_events.pop_front();
    }

    if (shouldUpdate) {
        emit updateScene();
    }
}

void Game::setShouldUpdate() {
    shouldUpdate = true;
}

void Game::load_tiles(const QString &tile_map_file_name, const QString &map_file_name, std::vector<Sprite*> &tiles) {
    int tile_width = 16, tile_height = 16;

    // load in array of tiles from 0..n, n begin the amount of tiles in the tile_map_file_name.
    QPixmap tile_map = QPixmap(tile_map_file_name);

    std::vector<QPixmap> images;
    for (int y = 0; y < tile_map.height(); y += tile_height) {
        for (int x = 0; x < tile_map.width(); x += tile_width) {
            images.emplace_back(tile_map.copy(x,y, tile_width, tile_height));
        }
    }

    QFile file(map_file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }

    // copy csv into map
    std::vector<std::vector<int>> map;
    int row = 0;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        auto nums = line.split(',');
        map.emplace_back(std::vector<int>());
        for(int i = 0; i < nums.count(); i++) {
            //std::cout << nums[i].toInt() << " ";
            map[row].emplace_back(nums[i].toInt());
        }
        //std::cout << std::endl;
        row++;
    }

    // Create sprite objects according to csv map.
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            int tile = map[y][x];
            std::cout << tile << " ";
            //std::cout << "(" << x << "," << y << ")";
            if (tile >= 0) {
                auto sprite = new Sprite(images[tile]);
                sprite->setPosition(x , y);
                tiles.emplace_back(sprite);
            }
        }
        std::cout << std::endl;
    }
}

void Game::load_entities(const QString &map_file_name, std::vector<Entity *> &entities) {
    player = new Player(QPixmap("resources/player.png"));
    entities.emplace_back(player);
}

void Game::keyPressEvent(QKeyEvent *event) {
    key_events.push_back(event->key());
}
