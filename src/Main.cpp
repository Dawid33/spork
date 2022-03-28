#include <QApplication>
#include "MainWindow.hpp"
#include "Globals.hpp"

int baseScreenWidth = 1280;
int baseScreenHeight = 720;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow window(nullptr);
    window.show();
    return a.exec();
}
