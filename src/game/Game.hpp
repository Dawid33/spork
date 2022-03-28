#ifndef SPORK_GAMEWORLD_H
#define SPORK_GAMEWORLD_H

#include <QThread>
#include <QOpenGLTexture>
#include <QVBoxLayout>
#include <deque>
#include "../GameScene.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "../GameView.hpp"

class Game : public QThread {
    Q_OBJECT
public:
    friend GameView;

    explicit Game(QWidget *parent);
    void stop();
    void keyPressEvent(QKeyEvent *event);

protected:
    void run() override;
    void update();
private:
    void load_tiles(const QString &tile_map_file_name, const QString &map_file_name, std::vector<Sprite *> &tiles);
    
    bool isRunning = true;
    bool isPaused = false;
    bool shouldUpdate = false;

    std::deque<int> key_events;
    QTimer *game_tick_timer;
    std::vector<Sprite*> tiles;
    std::vector<Entity*> entities;
    Player* player;

signals:
    void updateScene();
    void moveViewport(int x, int y);
public slots:
    void setShouldUpdate();

    void load_entities(const QString &tile_image_name, const QString &tiles, std::vector<Entity *> &entities);
};


#endif //SPORK_GAMEWORLD_H
