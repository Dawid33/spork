#include "StatusConsoleDock.hpp"

StatusConsoleDock::StatusConsoleDock(QWidget *parent) : QDockWidget(parent) {
    console = new StatusConsole(this);
    setWidget(console);
}
