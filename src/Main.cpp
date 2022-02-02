#include <QApplication>
#include "Application.hpp"
#include "Globals.h"
int ui_scale = 5;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Application window(nullptr);
    window.show();
    return a.exec();
}
