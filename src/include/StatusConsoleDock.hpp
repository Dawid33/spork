#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QDockWidget>
#include <QHBoxLayout>
#include "StatusConsole.hpp"
#include "DockTitleBar.hpp"

class StatusConsoleDock : public QDockWidget {
public:
    explicit StatusConsoleDock(QWidget* parent);
    StatusConsole *console;
private:
    DockTitleBar *title_bar;
};

#endif // STATUS_BAR_H