#ifndef SPORK_MAINWINDOW_HPP
#define SPORK_MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include "GameScene.hpp"
#include "ui/StatusConsoleDock.hpp"
#include "game/Game.hpp"
#include "ui/control_panel/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"
#include "ui/menu_bar/ResolutionsMenu.hpp"
#include "GameView.hpp"
#include "Wordle.hpp"

class QPushButton;
class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void resizeEvent(QResizeEvent *event) override;

    void createMenuBar();
private slots:
    void selectedItem(InventoryItem *item);
    void usedItem(InventoryItem *item);
    void printToConsole(const QString&);
    void startWordle();
    void checkWordle(const QString&);
private:

    Game *game;
    GameView *game_view;
    Wordle* wordle;

    GameScene *scene;
    ControlPanelDock *control_panel_dock;
    StatusConsoleDock *console_dock;
};

#endif //SPORK_MAINWINDOW_HPP
