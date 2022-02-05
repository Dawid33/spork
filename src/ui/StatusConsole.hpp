#ifndef SPORK_STATUSCONSOLE_H
#define SPORK_STATUSCONSOLE_H

#include <QTextEdit>
#include <QGraphicsView>

class StatusConsole : public QWidget {
public:
    explicit StatusConsole(QWidget* parent = nullptr);
    QPixmap border;
    QPixmap border_base;
protected:
    void paintEvent(QPaintEvent *);
private:
    QGraphicsScene *scene;
};


#endif //SPORK_STATUSCONSOLE_H
