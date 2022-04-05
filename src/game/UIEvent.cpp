//
// Created by dawids on 29/03/2022.
//

#include "UIEvent.hpp"

UIEvent::UIEvent(const QString &item_type) : item_type(item_type) {
    type.UsedItem = 1;
}

UIEvent::UIEvent(const UIEvent &value) {
    this->item_type = value.item_type;
    this->type = value.type;
}