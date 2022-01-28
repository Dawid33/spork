#ifndef SPORK_APPLICATION_HPP
#define SPORK_APPLICATION_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "GameCanvas.hpp"
#include "StatusConsoleDock.hpp"
#include "Game.hpp"
#include "ControlPanel.hpp"

class QPushButton;
class Application : public QMainWindow
{
public:
    explicit Application(QWidget *parent = nullptr);
    ~Application() override;
private:
    Game *game;

    QDockWidget *right_dock;
    QToolBar *tool_bar;
    StatusConsoleDock *console_dock;
    ControlPanel *control_panel;
    QBoxLayout *central_widget_layout;
};

#endif //SPORK_APPLICATION_HPP
