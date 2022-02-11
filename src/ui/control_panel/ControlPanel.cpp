#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include "ControlPanel.hpp"
#include "../../Globals.hpp"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/right.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());

    use_btn = new InventoryButton(this, QPixmap("./resources/use_button.png"));
    drop_btn = new InventoryButton(this, QPixmap("./resources/drop_button.png"));
    inventory_view = new InventoryGridView(this, QPixmap("./resources/drop_button.png"));
    inventory_model = new InventoryGridModel(this);
    inventory_view->setModel(inventory_model);

    original_size = QVector2D(border.width(), border.height());
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}

void ControlPanel::resizeEvent(QResizeEvent *event) {
    QVector2D diff = QVector2D(((float)event->size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)event->size().height() - original_size.y()) / original_size.y() + 1);

    use_btn->move(72 * diff.x(), 103.0 * diff.y());
    use_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());
    drop_btn->move(72 * diff.x(), 114.0 * diff.y());
    drop_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());

    QWidget::resizeEvent(event);
}

InventoryButton *ControlPanel::getUseButton() {
    return use_btn;
}
