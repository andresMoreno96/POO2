#include "Buffy.hpp"

Buffy::Buffy(const Manager& manager, const Cell& cell) : Person(manager, cell) {

}

void Buffy::move() {
    size_t dx;
    size_t dy;

    // If there is any vampire left then chase it
    if(getManager().hasVampire()) {
        Vampire neareastEnemy = getManager().nearestEnemyFrom(this);
        size_t enemyX = neareastEnemy.getX();
        size_t enemyY = neareastEnemy.getY();

    }
}

