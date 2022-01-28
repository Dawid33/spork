#include "StatusConsole.hpp"

StatusConsole::StatusConsole(QWidget *parent) : QTextEdit(parent) {
    setStyleSheet("QTextEdit { border-image: url(:/resources/border.png); border-width : 30px; color : white; }");
}
