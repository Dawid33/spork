#ifndef SPORK_INVENTORYBUTTON_HPP
#define SPORK_INVENTORYBUTTON_HPP

#include <QAbstractButton>

class InventoryButton : public QAbstractButton {
public:
    explicit InventoryButton(QWidget* parent, QPixmap background);
protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap background_image;
};


#endif //SPORK_INVENTORYBUTTON_HPP
