#include "DockTitleBar.hpp"

DockTitleBar::DockTitleBar(QString title, QWidget *parent) : QLabel(title, parent) {
    setStyleSheet("QLabel { background : red }");
}
