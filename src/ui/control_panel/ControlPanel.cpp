#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include <valarray>
#include "ControlPanel.hpp"
#include "InventoryItem.hpp"
#include <QDebug>
#include <QLineEdit>

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/right.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());

    use_btn = new InventoryButton(this, QPixmap("./resources/use_button.png"));
    drop_btn = new InventoryButton(this, QPixmap("./resources/drop_button.png"));
    inventory_grid = new InventoryGrid(this, QPixmap("./resources/inventory_item.png"));
    wordle_box = new QLineEdit(this);
    auto font = wordle_box->font();
    font.setPointSize(22);
    wordle_box->setFont(font);
    //wordle_box->setVisible(false);

    inventory_grid->setItem(0,0,new InventoryItem("Sword", QPixmap("./resources/sword.png")));

    connect(inventory_grid, &InventoryGrid::cellClicked, this, &ControlPanel::clickedInventoryCell);
    connect(use_btn, &InventoryButton::clicked, this, &ControlPanel::useButtonPressed);
    connect(wordle_box, &QLineEdit::returnPressed, this, &ControlPanel::enteredWordle);

    original_size = QVector2D(border.width(), border.height());
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}

void ControlPanel::resizeEvent(QResizeEvent *event) {
    QVector2D diff = QVector2D(((float)event->size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)event->size().height() - original_size.y()) / original_size.y() + 1);

    // Move sub-widgets in control panel based on position in base image.
    use_btn->move(72 * diff.x(), 103.0 * diff.y());
    use_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());

    drop_btn->move(72 * diff.x(), 114.0 * diff.y());
    drop_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());

    inventory_grid->setFixedSize(84 * diff.x(), 50 * diff.y());
    inventory_grid->move((int)(9.0f * diff.x()), (int)(41.0f * diff.y()));

    wordle_box->setFixedSize(84 * diff.x(), 20 * diff.y());
    wordle_box->move((int)(9.0f * diff.x()), (int)(190.0f * diff.y()));

    QWidget::resizeEvent(event);
}

InventoryButton *ControlPanel::useButton() {
    return use_btn;
}

InventoryGrid *ControlPanel::inventory() {
    return inventory_grid;
}

void ControlPanel::clickedInventoryCell(int row, int column) {
    emit selectedItem((InventoryItem*)inventory_grid->item(row, column));
}

void ControlPanel::useButtonPressed(bool) {
    auto items = inventory_grid->selectedItems();
    if (!items.isEmpty()) {
        emit clickedUseButton((InventoryItem*)items.at(0));
    }
}

void ControlPanel::enteredWordle() {
    if (wordle_box->text().length() == 5) {
        emit gotWordle(wordle_box->text());
    }
}

void ControlPanel::toggleWordle(bool visible) {
    wordle_box->setVisible(visible);
}
