//
// Created by dawids on 26/02/2022.
//

#include <QPainter>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "DrawInventoryItem.hpp"
#include "InventoryItem.hpp"

DrawInventoryItem::DrawInventoryItem(QWidget *parent, QPixmap background) : QStyledItemDelegate(parent){
    this->background = background;
}

void DrawInventoryItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    auto table = ((QTableWidget*)parent());
    QRect rect = table->visualRect(index);

    painter->drawPixmap(rect.x(), rect.y(), rect.width(), rect.height(), this->background);

    auto item = (InventoryItem*)table->item(index.row(), index.column());
    if (item != nullptr) {
        painter->drawPixmap(rect.x() + rect.width() * 0.1, rect.y() + rect.height() * 0.1, rect.width() * 0.8, rect.height() * 0.8, item->getBackground());
    }
    QStyledItemDelegate::paint(painter, option, index);
}
