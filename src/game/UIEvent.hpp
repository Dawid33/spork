//
// Created by dawids on 29/03/2022.
//

#ifndef SPORK_UIEVENT_H
#define SPORK_UIEVENT_H

#include "../ui/control_panel/InventoryItem.hpp"

enum EventType {
    UsedItem
};

class UIEvent {
public:
    UIEvent(QString item_type);
    EventType type;
    QString item_type;
};


#endif //SPORK_UIEVENT_H
