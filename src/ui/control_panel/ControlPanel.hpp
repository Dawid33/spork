#ifndef SPORK_CONTROL_PANEL_H
#define SPORK_CONTROL_PANEL_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVector2D>
#include "InventoryButton.hpp"
#include "InventoryGrid.hpp"
#include "InventoryItem.hpp"

class ControlPanel : public QWidget {
    Q_OBJECT
public:
    explicit ControlPanel(QWidget* parent);
    InventoryButton* useButton();
    InventoryGrid* inventory();

    QPixmap border;
    QPixmap border_base;
protected slots:
    void clickedInventoryCell(int row, int column);
    void useButtonPressed(bool);
signals:
    void selectedItem(InventoryItem *item);
    void clickedUseButton(InventoryItem *item);
protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    InventoryButton *use_btn;

    InventoryButton *drop_btn;

    InventoryGrid *inventory_grid;

    QVector2D original_size;
};


#endif //SPORK_CONTROL_PANEL_H
