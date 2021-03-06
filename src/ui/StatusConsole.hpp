#ifndef SPORK_STATUSCONSOLE_H
#define SPORK_STATUSCONSOLE_H

#include <QTextEdit>
#include <QGraphicsView>
#include <QVector2D>

class StatusConsole : public QWidget {
public:
    explicit StatusConsole(QWidget* parent = nullptr);
    QPixmap border;
    QPixmap border_base;
    void append_text(const QString &text);
    void clear();
    QTextEdit* getTextEdit();
protected:
    void paintEvent(QPaintEvent *) override;
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QTextEdit *text_edit;
    QGraphicsScene *scene;

    QVector2D original_size;
};


#endif //SPORK_STATUSCONSOLE_H
