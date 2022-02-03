#ifndef SPORK_DOCKTITLEBAR_H
#define SPORK_DOCKTITLEBAR_H

#include <QFrame>
#include <QLabel>

class DockTitleBar : public QLabel {
public:
    explicit DockTitleBar(QString title, QWidget* parent, const char *image_path);
private:
    QPixmap background_image;

    void paintEvent(QPaintEvent *);
};


#endif //SPORK_DOCKTITLEBAR_H
