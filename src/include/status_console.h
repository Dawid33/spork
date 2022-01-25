#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QDockWidget>

class StatusConsole : public QDockWidget {
public:
    explicit StatusConsole(const QString &title, QWidget* parent = nullptr);
};

#endif // STATUS_BAR_H