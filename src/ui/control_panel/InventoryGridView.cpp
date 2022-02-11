
#include <QWidget>
#include <QHeaderView>
#include <QPainter>
#include "InventoryGridView.hpp"

InventoryGridView::InventoryGridView(QWidget *parent, QPixmap background) {
    background_image = background;

    auto header = new QHeaderView(Qt::Horizontal, this);
    setVerticalHeader(header);
    setShowGrid(true);
}

void InventoryGridView::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.drawPixmap(0,0,this->width(), this->height(), background_image);
}

void InventoryGridView::resizeEvent(QResizeEvent *event) {

    QTableView::resizeEvent(event);
}
