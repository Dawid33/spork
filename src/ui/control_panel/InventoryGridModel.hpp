#ifndef SPORK_INVENTORYGRIDMODEL_HPP
#define SPORK_INVENTORYGRIDMODEL_HPP

#include <QAbstractTableModel>

class InventoryGridModel : public QAbstractTableModel {
public:
    explicit InventoryGridModel(QWidget *parent);
protected:
    QVariant data(const QModelIndex &index, int role) const override;
    int columnCount(const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent) const override;
private:

};


#endif //SPORK_INVENTORYGRIDMODEL_HPP
