//
// Created by dawids on 29/03/2022.
//

#include "UIEvent.hpp"

UIEvent::UIEvent(QString item_type) {
    type = EventType::UsedItem;
    this->item_type = item_type;
}
