#ifndef SPORK_INVENTORYGRID_HPP
#define SPORK_INVENTORYGRID_HPP

#include <QPixmap>
#include <QTableWidget>
#include <QPaintEvent>

class InventoryGrid : public QTableWidget {
    Q_OBJECT
public:
    explicit InventoryGrid(QWidget* parent, QPixmap background);
protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *) override;
private:
    QPixmap background_image;
};


#endif //SPORK_INVENTORYGRID_HPP
