#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include "ControlPanel.hpp"
#include "../../Globals.hpp"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/right.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());
    std::cout << size().width() << " " << size().height() << std::endl;

    original_size = QVector2D(border.width(), border.height());

    QVector2D diff = QVector2D(((float)size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)size().height() - original_size.y()) / original_size.y() + 1);

    use_btn = new InventoryButton(this);
    use_btn->setText("Hello");
    use_btn->show();
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}

void ControlPanel::resizeEvent(QResizeEvent *event) {
    QVector2D diff = QVector2D(((float)event->size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)event->size().height() - original_size.y()) / original_size.y() + 1);
    //std::cout << original_size.x() << " " << event->size().width() << " " << diff.y() << std::endl;

    use_btn->move(72 * diff.x(), 103.0 * diff.y());
    use_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());

    QWidget::resizeEvent(event);
}

InventoryButton *ControlPanel::getUseButton() {
    return use_btn;
}
