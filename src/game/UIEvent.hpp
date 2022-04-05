//
// Created by dawids on 29/03/2022.
//

#ifndef SPORK_UIEVENT_H
#define SPORK_UIEVENT_H

#include "../ui/control_panel/InventoryItem.hpp"

struct EventType {
    unsigned short UsedItem :1;
    unsigned short SolvedWordle :1;
};

class UIEvent {
public:
    UIEvent(const UIEvent &value);
    UIEvent(const QString &value);

    EventType type;
    QString item_type;
};


#endif //SPORK_UIEVENT_H
