#ifndef SPORK_DOCKTITLEBAR_H
#define SPORK_DOCKTITLEBAR_H

#include <QFrame>
#include <QLabel>

class DockTitleBar : public QLabel {
public:
    explicit DockTitleBar(QString title, QWidget* parent);
};


#endif //SPORK_DOCKTITLEBAR_H
