#ifndef SPORK_CONTROLPANELDOCK_H
#define SPORK_CONTROLPANELDOCK_H

#include <QDockWidget>
#include "ControlPanel.hpp"
#include "DockTitleBar.hpp"

class ControlPanelDock : public QDockWidget {
public:
    explicit ControlPanelDock(QWidget* parent);
private:
    ControlPanel *control_panel;
    DockTitleBar *title_bar;
};


#endif //SPORK_CONTROLPANELDOCK_H
