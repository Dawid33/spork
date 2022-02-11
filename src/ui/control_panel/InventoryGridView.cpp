
#include <QWidget>
#include <QHeaderView>
#include <QPainter>
#include "InventoryGridView.hpp"

InventoryGridView::InventoryGridView(QWidget *parent, QPixmap background) {
    background_image = background;

    auto header = new QHeaderView(Qt::Horizontal, this);
    setVerticalHeader(header);
    setShowGrid(true);
    setFixedWidth(300);
    setFixedHeight(300);
}

void InventoryGridView::paintEvent(QPaintEvent *event) {


    QTableView::paintEvent(event);
}

void InventoryGridView::resizeEvent(QResizeEvent *event) {

    QTableView::resizeEvent(event);
}
