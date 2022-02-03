#include <QApplication>
#include "Application.hpp"
#include "Globals.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Application window(nullptr);
    window.show();
    return a.exec();
}
