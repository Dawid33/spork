#include <QWidget>
#include <QAbstractTableModel>
#include "InventoryGridModel.hpp"

InventoryGridModel::InventoryGridModel(QWidget *parent) : QAbstractTableModel(parent) {

}

QVariant InventoryGridModel::data(const QModelIndex &index, int role) const {
    return QVariant();
}

int InventoryGridModel::columnCount(const QModelIndex &parent) const {
    return 0;
}

int InventoryGridModel::rowCount(const QModelIndex &parent) const {
    return 0;
}
