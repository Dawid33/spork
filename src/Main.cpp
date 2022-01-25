#include <QApplication>
#include <QPushButton>
#include "Application.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Application window(nullptr);
    window.show();
    return a.exec();
}
