#include "StatusConsoleDock.hpp"
#include <QSizePolicy>

StatusConsoleDock::StatusConsoleDock(QWidget *parent) : QDockWidget(parent) {
    console = new StatusConsole(this);
    title_bar = new DockTitleBar("Status Console Dock", this, "./resources/console_title.png");
    QSizePolicy size_policy = QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    setSizePolicy(size_policy);

    setTitleBarWidget(title_bar);
    setWidget(console);
}
