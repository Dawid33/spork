#include <QDomDocument>
#include "Game.hpp"
#include "Wizard.hpp"
#include <QTimer>
#include <QConstOverload>
#include <QFile>
#include <QDebug>
#include <QKeyEvent>

#define PLAYER_TILE 190
#define WIZARD_TILE 197

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
    if (key_events.empty()) {
        player->setMoveDirection(0,0);
    }

    while(!key_events.empty()) {
        int key = key_events.front();
        if (key == Qt::Key_W) {
            player->setMoveDirection(0,1);
        } else if (key == Qt::Key_D) {
            player->setMoveDirection(1,0);
        } else if (key == Qt::Key_A) {
            player->setMoveDirection(-1,0);
        } else if (key == Qt::Key_S) {
            player->setMoveDirection(0,-1);
        }
        key_events.pop_front();
    }

    while(!ui_events.empty()) {
        UIEvent event = ui_events.front();
        switch(event.type) {
            case UsedItem:
                emit pushToConsole(QString("Used Item : ") + event.item_type);
                bool did_something = false;
                if (event.item_type == "Sword") {
                    for (int i = 0; i < entities.size(); i++) {
                        if (QRect(player->getPosition() - QPoint(player->getPixmap().size().width(), player->getPixmap().size().height()), player->getPixmap().size() * 3).intersects(entities[i]->getCollisionRectangle())
                            && entities[i]->type == "wizard") {
                            if (((Wizard*)entities[i])->is_alive) {
                                ((Wizard*)entities[i])->is_alive = false;
                                emit updateScene();
                                emit pushToConsole("Wizard : Blast! You have defeated me! To take my treasure you will first have to solve the riddle to open my vault!");
                                emit pushToConsole("Wizard : *dies*");
                                did_something = true;
                            }
                        }
                    }
                }
                if (!did_something){
                    emit pushToConsole("You accomplished nothing.");
                }
            break;
        }

        ui_events.pop_front();
    }

    if (player->getMoveDirection().x() != 0 || player->getMoveDirection().y() != 0) {
        player->move(player->getMoveDirection());
        for(Entity* e : entities) {
            if( QRect(player->getPosition(), player->getPixmap().size()).intersects(e->getCollisionRectangle())) {
                if (!e->has_entered) {
                    e->has_entered = true;
                    QString s = e->getOnEnterString();
                    emit pushToConsole(s);
                }
            }
        }

        emit moveViewport(player->getPosition().x(), player->getPosition().y());
        emit updateScene();
    }
}

void Game::setShouldUpdate() {
    shouldUpdate = true;
}

QDomDocument load_document(const QString &filepath) {
    QDomDocument doc("main");
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    if (!doc.setContent(&file)) {
        qDebug() << "Cannot set content of QDomDocument";
        file.close();
        return doc;
    }
    file.close();
    return doc;
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

    auto doc = load_document("resources/main.tmx");

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
    // Get entities from the entities tile layer
    load_tiles(tile_image_name, tiles, raw);

    while(!raw.empty()) {
        if (raw.back()->getImageId() == PLAYER_TILE) {
            player = new Player(raw.back()->getPixmap());
            player->setPosition(raw.back()->getPosition());
            entities.push_back(player);
        } else if (raw.back()->getImageId() == WIZARD_TILE) {
            Wizard* e = new Wizard(raw.back()->getPixmap());
            e->setPosition(raw.back()->getPosition());
            e->setCollisionRectable(QRect(raw.back()->getPosition(), e->getPixmap().size()));
            e->type = "wizard";
            entities.push_back(e);
        } else {
            Entity* e = new Entity(raw.back()->getPixmap());
            e->setPosition(raw.back()->getPosition());
            entities.push_back(e);
        }
        raw.pop_back();
    }

    // Get "zones" from the object layer.
    auto doc = load_document("resources/main.tmx");
    auto objects = doc.elementsByTagName("object");
    for (int i = 0; i < objects.length(); i++) {
        Entity* entity = new Entity();

        auto object = objects.at(i);
        auto attributes = object.attributes();
        auto x = attributes.namedItem("x").toAttr().value().toFloat();
        auto y = attributes.namedItem("y").toAttr().value().toFloat();
        auto width = attributes.namedItem("width").toAttr().value().toFloat();
        auto height = attributes.namedItem("height").toAttr().value().toFloat();
        entity->setCollisionRectable(QRect(x,y,width,height));

        auto object_properties = object.attributes();
        auto properties = object.firstChild().childNodes();
        for (int j = 0; j < properties.length(); j++) {
            auto property = properties.at(j);
            auto name = property.attributes().namedItem("name").toAttr().value();
            auto value = property.attributes().namedItem("value").toAttr().value();
            if (name == QString("Text")) {
                entity->setOnEnterString(value);
            }
        }
        entities.push_back(entity);
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    key_events.push_back(event->key());
}

Game::~Game() {
//    for (Entity* e : entities) {
//        delete e;
//    }
//    for (Sprite* s : tiles) {
//        delete s;
//    }
}

void Game::uiEvent(UIEvent event) {
    ui_events.push_back(event);
}
