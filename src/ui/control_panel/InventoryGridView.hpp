#ifndef SPORK_INVENTORYGRIDVIEW_HPP
#define SPORK_INVENTORYGRIDVIEW_HPP

#include <QAbstractTableModel>
#include <QPixmap>
#include <QTableView>

class InventoryGridView : public QTableView {
public:
    explicit InventoryGridView(QWidget* parent, QPixmap background);
protected:
     void paintEvent(QPaintEvent *) override;
     void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap background_image;
};


#endif //SPORK_INVENTORYGRIDVIEW_HPP
