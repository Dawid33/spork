//
// Created by dawids on 06/02/2022.
//

#ifndef SPORK_INVENTORYBUTTON_HPP
#define SPORK_INVENTORYBUTTON_HPP

#include <QAbstractButton>

class InventoryButton : public QAbstractButton {
public:
    explicit InventoryButton(QWidget* parent = nullptr);
    QPixmap border;
    QPixmap border_base;
protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QPixmap background_image;
    QPixmap background_image_base;
};


#endif //SPORK_INVENTORYBUTTON_HPP
