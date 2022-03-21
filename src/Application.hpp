#ifndef SPORK_APPLICATION_HPP
#define SPORK_APPLICATION_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "game/GameScene.hpp"
#include "ui/StatusConsoleDock.hpp"
#include "game/Game.hpp"
#include "ui/control_panel/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"
#include "ui/menu_bar/ResolutionsMenu.hpp"
#include "game/GameView.hpp"


class QPushButton;
class Application : public QMainWindow
{
public:
    explicit Application(QWidget *parent = nullptr);
    ~Application() override;
    void resizeEvent(QResizeEvent *event) override;

    void createMenuBar();
private slots:
    void print_hello(InventoryItem *item);
private:
    Game *game;
    ControlPanelDock *control_panel_dock;
    GameView *game_view;
    GameScene *scene;

    StatusConsoleDock *console_dock;
    QWidget *central_widget_frame;

    QBoxLayout *central_widget_layout;

    QMenu *resolutions_menu;
};

#endif //SPORK_APPLICATION_HPP
