#include "StatusConsole.hpp"
#include <QPainter>
#include <QGraphicsView>

StatusConsole::StatusConsole(QWidget *parent) : QGraphicsView(parent) {
    //setStyleSheet("QTextEdit { border : 30px solid white; }");
    border = QPixmap("/resources/background.png");
    scene = new QGraphicsScene(this);
    scene->addPixmap(border);
    setScene(scene);
}

//void StatusConsole::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//
//    painter.setPen(QColor(255,34,255,255));
//    painter.drawRect(15,15,100,100);
//}
