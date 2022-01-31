#include "StatusConsoleDock.hpp"

StatusConsoleDock::StatusConsoleDock(QWidget *parent) : QDockWidget(parent) {
    console = new StatusConsole(this);
    title_bar = new DockTitleBar("Status Console Dock", this);

    setTitleBarWidget(title_bar);
    setWidget(console);
}
