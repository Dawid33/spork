//
// Created by dawids on 26/02/2022.
//

#ifndef SPORK_DRAWINVENTORYITEM_H
#define SPORK_DRAWINVENTORYITEM_H


#include <QStyledItemDelegate>

class DrawInventoryItem : public QStyledItemDelegate {
public:
    explicit DrawInventoryItem(QWidget *parent, QPixmap background);
protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:
    QPixmap background;
};


#endif //SPORK_DRAWINVENTORYITEM_H
