//
// Created by dawids on 28/01/2022.
//

#ifndef SPORK_CONTROL_PANEL_H
#define SPORK_CONTROL_PANEL_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVector2D>

class ControlPanel : public QWidget {
public:
    explicit ControlPanel(QWidget* parent = nullptr);
    QPixmap border;
    QPixmap border_base;
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *event);
private:
    QPushButton *test_btn;

    QVector2D original_size;
};


#endif //SPORK_CONTROL_PANEL_H
