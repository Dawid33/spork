//
// Created by dawids on 28/01/2022.
//

#ifndef SPORK_CONTROL_PANEL_H
#define SPORK_CONTROL_PANEL_H

#include <QWidget>
#include <QTextEdit>

class ControlPanel : public QWidget {
public:
    explicit ControlPanel(QWidget* parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap border;
};


#endif //SPORK_CONTROL_PANEL_H
