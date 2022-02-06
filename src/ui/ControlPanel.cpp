#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include "ControlPanel.hpp"
#include "../Globals.hpp"

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/right.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());

    test_btn = new QPushButton(this);
    test_btn->setText("Hello");
    test_btn->move(72, 103);
    test_btn->setFixedSize(21,10);
    test_btn->show();

    original_size = QVector2D(border.width(), border.height());
}

void ControlPanel::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}

void ControlPanel::resizeEvent(QResizeEvent *event) {
    if (event->oldSize().width() < 0 || event->oldSize().height() < 0) {
        return QWidget::resizeEvent(event);
    }

    QVector2D diff = QVector2D(((float)event->size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)event->size().height() - original_size.y()) / original_size.y() + 1);
    std::cout << original_size.x() << " " << event->size().width() << " " << diff.x() << std::endl;

    test_btn->move(72 * diff.x(), 103.0 * diff.y());
    test_btn->setFixedSize(21 * diff.x(), 10.0 * diff.y());

    QWidget::resizeEvent(event);
}
