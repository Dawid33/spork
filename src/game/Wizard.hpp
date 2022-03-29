//
// Created by dawids on 29/03/2022.
//

#ifndef SPORK_WIZARD_H
#define SPORK_WIZARD_H
#include "Entity.hpp"

class Wizard : public Entity {
public:
    Wizard(QPixmap pixmap);

    void updateGraphics() override;
    bool is_alive = true;
};


#endif //SPORK_WIZARD_H
