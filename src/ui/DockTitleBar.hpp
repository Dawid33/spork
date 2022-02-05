#ifndef SPORK_DOCKTITLEBAR_H
#define SPORK_DOCKTITLEBAR_H

#include <QFrame>
#include <QLabel>

class DockTitleBar : public QLabel {
public:
    explicit DockTitleBar(QString title, QWidget* parent, const char *image_path);
    QPixmap background_image;
    QPixmap background_image_base;
protected:
    void paintEvent(QPaintEvent *); 
private:

};


#endif //SPORK_DOCKTITLEBAR_H
