#include "StatusConsole.hpp"
#include <QPainter>
#include <iostream>
#include <QResizeEvent>
#include <QScrollBar>
#include "../Globals.hpp"

StatusConsole::StatusConsole(QWidget *parent) : QWidget(parent) {
    border_base = QPixmap("./resources/bottom.png");
    border = border_base;
    setMinimumHeight(border.height());
    setMinimumWidth(border.width());

    text_edit = new QTextEdit(this);
    text_edit->setStyleSheet("QTextEdit { background-color : rgb(78,74,78); }");
    text_edit->setTextColor(QColor(255,255,255));
    text_edit->setFrameStyle(QFrame::NoFrame);
    text_edit->move(10, 10);
    text_edit->setFixedSize(size().width() - 20.0f, size().height() - 20.0f);
    text_edit->setFontPointSize(10.0);
    text_edit->setText("Sample text");
    text_edit->setTextInteractionFlags(Qt::TextBrowserInteraction);


    original_size = QVector2D(size().width(),size().height());
}

void StatusConsole::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), border);
}

void StatusConsole::resizeEvent(QResizeEvent *event) {
    if (event->oldSize().width() < 0 || event->oldSize().height() < 0) {
        return QWidget::resizeEvent(event);
    }

    QVector2D diff = QVector2D(((float)event->size().width() - original_size.x()) / original_size.x() + 1,
                               ((float)event->size().height() - original_size.y()) / original_size.y() + 1);

    text_edit->move(10 * diff.x(), 10 * diff.y());
    text_edit->setFixedSize((original_size.x() - 20.0f) * diff.x(), (original_size.y() - 20.0f) * diff.y());
}

QSize StatusConsole::sizeHint() const {
    return border.size();
}

void StatusConsole::append_text(QString text) {
    QScrollBar *scrollbar = text_edit->verticalScrollBar();
    bool scrollbarAtBottom  = (scrollbar->value() >= (scrollbar->maximum() - 4));
    int scrollbarPrevValue = scrollbar->value();
    text_edit->append(text);
    if (scrollbarAtBottom)
        text_edit->ensureCursorVisible();
    else
        text_edit->verticalScrollBar()->setValue(scrollbarPrevValue);
}

/*
    // Corners
    // Top Left
    painter.drawPixmap(0, 0, 5 * scale, 5 * scale, border, 0, 0, 5, 5);
    // Bottom Left
    painter.drawPixmap(0, (image_height - 5)*scale, 5*scale, 5*scale, border, 0, image_height - 5, 5, 5);
    // Top Right
    painter.drawPixmap(this->width()-(5*scale), 0, 5*scale, 5*scale, border, image_width-5, 0, 5, 5);
    // Bottom Right
    painter.drawPixmap(this->width()-(5*scale), (image_height-5)*scale, 5*scale, 5*scale, border, image_width-5, image_height-5, 5, 5);

    // Center
    painter.drawPixmap(5*scale, 5*scale, this->width()-(10*scale), this->height()-(10*scale), border, 5, 5, image_width - 10, image_height - 10);

    // Edges
    // Left
    painter.drawPixmap(0, 5*scale, 5*scale, (image_height-10)*scale, border, 0, 5, 5, image_height - 10);
    // Right
    painter.drawPixmap(this->width()-(5*scale), 5*scale, 5*scale, (image_height-10)*scale, border, image_width - 5, 5, 5, image_height - 10);
    //Top
    painter.drawPixmap(5*scale, 0, (image_width-10)*scale, 5*scale, border, 5, 0, image_width - 10, 5);
 */
