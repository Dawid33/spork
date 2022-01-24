#ifndef SPORK_WINDOW_H
#define SPORK_WINDOW_H

#include <QMainWindow>
#include <QPushButton>

class QPushButton;
class Window : public QMainWindow
{
public:
    explicit Window(QWidget *parent = 0);
private:
    QPushButton *button;
    WorldCanvas
};

#endif //SPORK_WINDOW_H
