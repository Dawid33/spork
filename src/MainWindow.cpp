#include <iostream>
#include <QDesktopWidget>
#include <QMenuBar>
#include <QDebug>
#include <QResizeEvent>
#include "MainWindow.hpp"
#include "ui/StatusConsoleDock.hpp"
#include "game/Game.hpp"
#include "ui/control_panel/ControlPanel.hpp"
#include "ui/ControlPanelDock.hpp"
#include "ui/control_panel/InventoryItem.hpp"
#include <QTimer>
#include "Globals.hpp"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->resize(Global::baseScreenWidth, Global::baseScreenHeight);
    setStyleSheet("QMainWindow {background : lightblue;}");

    game = new Game(this);
    game->start();
    game_view = new GameView(game, new GameScene(this));
    wordle = new Wordle();

    connect(game, &Game::pushToConsole, this, &MainWindow::printToConsole);
    connect(game, &Game::startWordle, this, &MainWindow::startWordle);

    QTransform trans;
    trans.scale(2.5,2.5);
    game_view->setTransform(trans, true);

    control_panel_dock = new ControlPanelDock(this);
    console_dock = new StatusConsoleDock( this);

    setCorner(Qt::Corner::BottomRightCorner, Qt::DockWidgetArea::RightDockWidgetArea);
    setCorner(Qt::Corner::BottomLeftCorner, Qt::DockWidgetArea::LeftDockWidgetArea);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, console_dock);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, control_panel_dock);

    // Connect UI Buttons.
    connect((ControlPanel*)control_panel_dock->widget(), &ControlPanel::clickedUseButton,
            this, &MainWindow::usedItem);
    connect(((ControlPanel*)control_panel_dock->widget()), &ControlPanel::selectedItem,
            this, &MainWindow::selectedItem);
    connect((ControlPanel*)control_panel_dock->widget(), &ControlPanel::gotWordle, this, &MainWindow::checkWordle);

    setCentralWidget(game_view);
}

MainWindow::~MainWindow() {
    game->stop();
    delete wordle;
    delete this->game;
}

void MainWindow::selectedItem(InventoryItem *item) {
    if (console_dock->widget() != nullptr && item != nullptr) {
        auto *console = (StatusConsole*)console_dock->widget();
        QString s = QString("Item : %1").arg(item->getName());
        console->append_text(s);
    }
}

void MainWindow::usedItem(InventoryItem *item) {
    game->uiEvent(UIEvent(item->getName()));
}

void MainWindow::printToConsole(const QString &value) {
    if (console_dock->widget() != nullptr) {
        auto *console = (StatusConsole*)console_dock->widget();
        console->append_text(value);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

void MainWindow::startWordle() {
    ((StatusConsole*)console_dock->widget())->clear();
    this->printToConsole("Wordle : type your guess in to the box on the bottom right hand corner.");
    this->printToConsole("The word has 5 letters.");
    ((ControlPanel*)control_panel_dock->widget())->toggleWordle(true);
}

void MainWindow::checkWordle(const QString &value) {
    auto editor = ((StatusConsole*)console_dock->widget())->getTextEdit();
    editor->clear();
    bool is_correct = wordle->guess(value);
    if (is_correct) {
        editor->clear();
        editor->insertPlainText("You have solved the wordle! Well done!");
    } else {
        wordle->print(editor);
        std::cout << *wordle << std::endl;
    }
}
