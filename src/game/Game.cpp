#include <QDomDocument>
#include "Game.hpp"
#include <QTimer>
#include <QConstOverload>
#include <QFile>
#include <QDebug>
#include <QKeyEvent>

#define PLAYER_TILE 190

Game::Game(QWidget *parent) : QThread(parent) {
    game_tick_timer = new QTimer();
    game_tick_timer->setInterval(20);
    connect(game_tick_timer, &QTimer::timeout, this, &Game::setShouldUpdate);
    game_tick_timer->start();

    load_tiles("resources/raw.png", "background_tiles", tiles);
    load_entities("resources/raw.png", "entities", entities);
}

void Game::run() {
    emit moveViewport(player->getPosition().x(), player->getPosition().y());
    emit updateScene();

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
    bool shouldUpdateGraphics = false;
    while(!key_events.empty()) {
        int key = key_events.front();
        if (key == Qt::Key_W) {
            player->move(0, 1);
            shouldUpdateGraphics = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_D) {
            player->move(1, 0);
            shouldUpdateGraphics = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_A) {
            player->move(-1, 0);
            shouldUpdateGraphics = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        } else if (key == Qt::Key_S) {
            player->move(0, -1);
            shouldUpdateGraphics = true;
            emit moveViewport(player->getPosition().x(), player->getPosition().y());
        }
        key_events.pop_front();
    }

    if (shouldUpdateGraphics) {
        emit updateScene();
    }
}

void Game::setShouldUpdate() {
    shouldUpdate = true;
}

void Game::load_tiles(const QString &tile_map_file_name, const QString &layer_name, std::vector<Sprite*> &tiles) {
    int tile_width = 16, tile_height = 16;

    // load in array of tiles from 0..n, n begin the amount of tiles in the tile_map_file_name.
    QPixmap tile_map = QPixmap(tile_map_file_name);

    std::vector<QPixmap> images;
    for (int y = 0; y < tile_map.height(); y += tile_height) {
        for (int x = 0; x < tile_map.width(); x += tile_width) {
            images.emplace_back(tile_map.copy(x,y, tile_width, tile_height));
        }
    }

    QDomDocument doc("main");
    QFile file("resources/main.tmx");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    if (!doc.setContent(&file)) {
        qDebug() << "Cannot set content of QDomDocument";
        file.close();
        return;
    }
    file.close();

    QStringList csv_data;
    auto layers = doc.elementsByTagName("layer");
    for(int i = 0; i < layers.length(); i++) {
        auto attributes = layers.at(i).attributes();
        for (int j = 0; j < attributes.length(); j++) {
            if (attributes.item(j).toAttr().name() == QString("name")) {
                if (attributes.item(j).toAttr().value() == layer_name) {
                    // Found layer node
                    auto data_node = layers.at(i).firstChild();
                    csv_data = data_node.toElement().text().split("\n");
                }
            }
        }
    }


    std::vector<std::vector<int>> map;
    for(int i = 0; i < csv_data.length(); i++) {
        auto nums = csv_data.at(i).split(",");
        map.emplace_back(std::vector<int>());
        for(int j = 0; j < nums.count(); j++) {
            map[i].emplace_back(nums[j].toInt());
        }
    }

    // Create sprite objects according to csv map.
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            int tile = map[y][x];
            //std::cout << tile << " ";
            //std::cout << "(" << x << "," << y << ")";
            if (tile > 0) {
                auto sprite = new Sprite(images[tile - 1]);
                sprite->setImageId(tile - 1);
                sprite->setPosition(x, y);
                tiles.emplace_back(sprite);
            }
        }
        //std::cout << std::endl;
    }
}

void Game::load_entities(const QString &tile_image_name, const QString &tiles, std::vector<Entity *> &entities) {
    std::vector<Sprite*> raw;
    load_tiles(tile_image_name, tiles, raw);
    while(!raw.empty()) {
        if (raw.back()->getImageId() == PLAYER_TILE) {
            player = new Player(raw.back()->getPixmap());
            player->setPosition(raw.back()->getPosition());
            qDebug() << "Position : " << player->getPosition();
            entities.push_back(player);
        } else {
            entities.push_back((Entity*)raw.back());
        }
        raw.pop_back();
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    key_events.push_back(event->key());
}
