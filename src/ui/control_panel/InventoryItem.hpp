#ifndef SPORK_INVENTORYITEM_H
#define SPORK_INVENTORYITEM_H

#include <QTableWidgetItem>

class InventoryItem : public QTableWidgetItem {
public:
    explicit InventoryItem(QString name, QPixmap background);
    QString getName();
    QPixmap& getBackground();
private:
    QString name;
    QPixmap background_image;
};


#endif //SPORK_INVENTORYITEM_H
