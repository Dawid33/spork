#ifndef SPORK_STATUSCONSOLE_H
#define SPORK_STATUSCONSOLE_H

#include <QTextEdit>
#include <QGraphicsView>

class StatusConsole : public QGraphicsView {
public:
    explicit StatusConsole(QWidget* parent = nullptr);

private:
    QPixmap border;
    QGraphicsScene *scene;
};


#endif //SPORK_STATUSCONSOLE_H
