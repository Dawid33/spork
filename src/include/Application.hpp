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
#include "ControlPanelDock.hpp"

class QPushButton;
class Application : public QMainWindow
{
public:
    explicit Application(QWidget *parent = nullptr);
    ~Application() override;
private:
    Game *game;

    ControlPanelDock *control_panel_dock;
    QToolBar *tool_bar;
    StatusConsoleDock *console_dock;
    QWidget *central_widget_frame;

    QBoxLayout *central_widget_layout;
    QBoxLayout *bottom_dock_layout;
    QBoxLayout *right_dock_layout;
};

#endif //SPORK_APPLICATION_HPP
