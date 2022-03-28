#ifndef SPORK_SPRITE_H
#define SPORK_SPRITE_H
#include <QGraphicsItem>
#include <memory>

class Sprite {
public:
    explicit Sprite(QPixmap image);

    void move(int x, int y);
    void updateGraphics();
    QGraphicsPixmapItem *graphicsItem();

    QPixmap getPixmap();

    void setPosition(int x, int y);
    void setPosition(QPoint p);
    QPoint getPosition();

    void setImageId(int id);
    int getImageId();

protected:
    QGraphicsPixmapItem *graphics_item;
    QPoint position;
    int image_id = 0;

private:
};


#endif //SPORK_SPRITE_H
