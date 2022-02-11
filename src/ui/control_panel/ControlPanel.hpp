#ifndef SPORK_CONTROL_PANEL_H
#define SPORK_CONTROL_PANEL_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVector2D>
#include "InventoryButton.hpp"
#include "InventoryGridView.hpp"
#include "InventoryGridModel.hpp"

class ControlPanel : public QWidget {
public:
    explicit ControlPanel(QWidget* parent);
    InventoryButton* getUseButton();

    QPixmap border;
    QPixmap border_base;
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *event);
private:
    InventoryButton *use_btn;
    InventoryButton *drop_btn;

    InventoryGridView *inventory_view;
    InventoryGridModel *inventory_model;

    QVector2D original_size;
};


#endif //SPORK_CONTROL_PANEL_H
