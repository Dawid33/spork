
#include <QWidget>
#include <QHeaderView>
#include <QResizeEvent>
#include <QPainter>
#include <QScrollBar>
#include <QTableWidget>
#include <iostream>
#include "InventoryGrid.hpp"
#include "DrawInventoryItem.hpp"

InventoryGrid::InventoryGrid(QWidget *parent, QPixmap background) : QTableWidget(3, 5, parent) {
    background_image = background;

    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);
    horizontalScrollBar()->setVisible(false);
    verticalScrollBar()->setVisible(false);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}");
    setSelectionMode(QAbstractItemView::SingleSelection);

    auto delegate = new DrawInventoryItem(this, background);
    setItemDelegate(delegate);

    setFrameStyle(QFrame::NoFrame);
    setShowGrid(false);
}

void InventoryGrid::resizeEvent(QResizeEvent *event) {
    for (int i = 0; i < rowCount(); i++) {
        setRowHeight(i, 0.3333333333333f * event->size().height());
    }
    double column_width = 0.2f * event->size().width();
    int actual = 0;
    for (int i = 0; i < columnCount(); i++) {
        setColumnWidth(i, column_width);
        actual += columnWidth(i);
    }
    // TODO : Columns can't be made smaller than some limit, try resizing the window height
    // with the below code.
    //std::cout << event->size().width() << ":" << actual << std::endl;
    QTableView::resizeEvent(event);
}

void InventoryGrid::paintEvent(QPaintEvent *event) {
    QTableWidget::paintEvent(event);
}
