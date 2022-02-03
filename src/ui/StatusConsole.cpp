#include "StatusConsole.hpp"
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "../Globals.hpp"

StatusConsole::StatusConsole(QWidget *parent) : QWidget(parent) {
    border = QPixmap("./resources/console_border.png");
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());
}

void StatusConsole::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);

}

/*
    // Corners
    // Top Left
    painter.drawPixmap(0, 0, 5 * scale, 5 * scale, border, 0, 0, 5, 5);
    // Bottom Left
    painter.drawPixmap(0, (image_height - 5)*scale, 5*scale, 5*scale, border, 0, image_height - 5, 5, 5);
    // Top Right
    painter.drawPixmap(this->width()-(5*scale), 0, 5*scale, 5*scale, border, image_width-5, 0, 5, 5);
    // Bottom Right
    painter.drawPixmap(this->width()-(5*scale), (image_height-5)*scale, 5*scale, 5*scale, border, image_width-5, image_height-5, 5, 5);

    // Center
    painter.drawPixmap(5*scale, 5*scale, this->width()-(10*scale), this->height()-(10*scale), border, 5, 5, image_width - 10, image_height - 10);

    // Edges
    // Left
    painter.drawPixmap(0, 5*scale, 5*scale, (image_height-10)*scale, border, 0, 5, 5, image_height - 10);
    // Right
    painter.drawPixmap(this->width()-(5*scale), 5*scale, 5*scale, (image_height-10)*scale, border, image_width - 5, 5, 5, image_height - 10);
    //Top
    painter.drawPixmap(5*scale, 0, (image_width-10)*scale, 5*scale, border, 5, 0, image_width - 10, 5);
 */
