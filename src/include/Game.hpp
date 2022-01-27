#ifndef SPORK_GAMEWORLD_H
#define SPORK_GAMEWORLD_H

#include <QThread>
#include <QOpenGLTexture>
#include "GameCanvas.hpp"

class Game : public QThread {
    Q_OBJECT
public:
    friend GameCanvas;

    explicit Game(QWidget *parent);
    ~Game() override;
    GameCanvas* getCanvas();
    void stop();
protected:
    void run() override;
private:
    void update();
    bool isRunning = true;

    bool isPaused = false;
    GameCanvas *canvas;
    QOpenGLTexture *yellow;
    QTimer *paint_timer;
    bool shouldPaintCanvas = false;
signals:
public slots:
    void paintCanvasAtNextUpdate();
};


#endif //SPORK_GAMEWORLD_H
