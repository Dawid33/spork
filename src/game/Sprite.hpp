#ifndef SPORK_SPRITE_H
#define SPORK_SPRITE_H
#include <QGraphicsItem>
#include <memory>

class Sprite {
public:
    explicit Sprite(QPixmap image);

    void move(int x, int y);
    void setPosition(int x, int y);
    void updateGraphics();
    QPoint getPosition();
    QGraphicsPixmapItem *graphicsItem();
protected:
    QGraphicsPixmapItem *graphics_item;
    QPoint position;

private:
};


#endif //SPORK_SPRITE_H
