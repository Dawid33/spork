#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QDockWidget>

class StatusBar : public QDockWidget {
public:
    explicit StatusBar(const QString &title, QWidget* parent = nullptr);
};

#endif // STATUS_BAR_H