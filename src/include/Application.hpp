#ifndef SPORK_APPLICATION_HPP
#define SPORK_APPLICATION_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "GameCanvas.hpp"
#include "StatusConsoleDock.hpp"
#include "Game.hpp"

class QPushButton;
class Application : public QMainWindow
{
public:
    explicit Application(QWidget *parent = nullptr);
    ~Application() override;
private:
    Game *game;

    QDockWidget *right;
    QToolBar *tool_bar;
    StatusConsoleDock *console_dock;
};

#endif //SPORK_APPLICATION_HPP
