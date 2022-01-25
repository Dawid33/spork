#ifndef SPORK_WINDOW_H
#define SPORK_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "world_canvas.h"
#include "status_console.h"

class QPushButton;
class Window : public QMainWindow
{
public:
    explicit Window(QWidget *parent = nullptr);
private:
    QPushButton *button;
    WorldCanvas *canvas;
    QDockWidget *right;
    QVBoxLayout *left;
    StatusConsole *status_bar;
    QToolBar *tool_bar;
};

#endif //SPORK_WINDOW_H
