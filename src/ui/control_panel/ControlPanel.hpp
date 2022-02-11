#ifndef SPORK_CONTROL_PANEL_H
#define SPORK_CONTROL_PANEL_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVector2D>
#include "InventoryButton.hpp"
#include "InventoryGrid.hpp"

class ControlPanel : public QWidget {
public:
    explicit ControlPanel(QWidget* parent = nullptr);
    InventoryButton* getUseButton();

    QPixmap border;
    QPixmap border_base;
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *event);
private:
    InventoryButton *use_btn;
    InventoryButton *drop_btn;

    InventoryGrid *inventory;

    QVector2D original_size;
};


#endif //SPORK_CONTROL_PANEL_H
