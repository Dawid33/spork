#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QDockWidget>
#include "StatusConsole.hpp"

class StatusConsoleDock : public QDockWidget {
public:
    explicit StatusConsoleDock(QWidget* parent);
private:
    StatusConsole *console{};
};

#endif // STATUS_BAR_H