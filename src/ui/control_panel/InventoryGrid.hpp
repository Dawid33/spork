#ifndef SPORK_INVENTORYGRID_HPP
#define SPORK_INVENTORYGRID_HPP

#include <QAbstractTableModel>
#include <QPixmap>

class InventoryGrid : public QAbstractTableModel {
public:
    explicit InventoryGrid(QWidget* parent, QPixmap background);
protected:
    // void paintEvent(QPaintEvent *) override;
    // void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap background_image;
};


#endif //SPORK_INVENTORYGRID_HPP
