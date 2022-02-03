#ifndef SPORK_STATUSCONSOLE_H
#define SPORK_STATUSCONSOLE_H

#include <QTextEdit>
#include <QGraphicsView>

class StatusConsole : public QWidget {
public:
    explicit StatusConsole(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap border;
    QGraphicsScene *scene;
};


#endif //SPORK_STATUSCONSOLE_H
