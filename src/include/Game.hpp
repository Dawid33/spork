#ifndef SPORK_GAMEWORLD_H
#define SPORK_GAMEWORLD_H

#include <QThread>
#include "GameCanvas.hpp"

class Game : public QThread {
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game() override;
    GameCanvas* getCanvas();
    void stop();
protected:
    void run() override;
private:
    bool isRunning = true;
    bool isPaused = false;
    GameCanvas *canvas;
signals:

public slots:

};


#endif //SPORK_GAMEWORLD_H
