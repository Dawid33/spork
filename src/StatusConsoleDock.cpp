#include "StatusConsoleDock.hpp"

StatusConsoleDock::StatusConsoleDock(const QString &title, QWidget *parent) : QDockWidget(title, parent) {
    this->console = new StatusConsole(this);
    setWidget(this->console);
}
