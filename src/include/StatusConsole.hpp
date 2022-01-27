#ifndef SPORK_STATUSCONSOLE_H
#define SPORK_STATUSCONSOLE_H

#include <QTextEdit>

class StatusConsole : public QTextEdit {
public:
    explicit StatusConsole(QWidget* parent = nullptr);
};


#endif //SPORK_STATUSCONSOLE_H
