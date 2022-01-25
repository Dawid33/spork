#ifndef SPORK_APPLICATION_HPP
#define SPORK_APPLICATION_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "GameCanvas.hpp"
#include "StatusConsole.hpp"
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
    StatusConsole *status_bar;
    QToolBar *tool_bar;
};

#endif //SPORK_APPLICATION_HPP
