#include "Field.hpp"
#include <time.h>

using namespace std;

const HumanoidType& Field::buffy   = HumanoidType("buffy");
const HumanoidType& Field::human   = HumanoidType("human");
const HumanoidType& Field::vampire = HumanoidType("vampire");

Field::Field(size_t width, size_t height, size_t nbHumans, size_t nbVampires) {
    // TODO: implement this

    // Générer la grille
    for(size_t y = 0; y < height; ++y) {
        for(size_t x = 0; x < width; ++x) {
            cells.push_back(new Cell(x, y));
        }
    }

    // Créer les humanoids

    // Créer Buffy
    Cell* cell = randomCell();
    humanoids.push_back(new Humanoid(*this, *cell, buffy));
    // cell->addHumanoid();

    // Créer les humains
    for(size_t human = 1; human < nbHumans; ++human) {

    }

    // Créer les vampires
    for(size_t vampire = 0; vampire < nbVampires; ++vampire) {

    }

}

Field::~Field() {
    // TODO: implement this

    for(size_t i = 0; i < cells.size(); ++i) {
        delete cells.at(i);
    }
}

int Field::nextTurn() {
    // NOTE: ne pas changer cette méthode, elle est tirée de la donnée !

    // Déterminer les prochaines actions
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);

    // Executer les actions
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);

    // Enlever les humanoides tués
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end();)
        if (!(*it)->isAlive()) {
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it;
            // destruction de l’humanoide référencé
        } else
            ++it;

    return turn++;
}

const Humanoid* Field::nearestFrom(const Humanoid& from, const HumanoidType& type) {
    size_t nearestDistance = -1; // -1 vas passer au max de size_t
    const Humanoid* nearest = nullptr;

    for(list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); ++it) {
        if((*it)->getType() != type) {
            continue;
        }

        int dx = from.getX() - (*it)->getX();
        int dy = from.getY() - (*it)->getY();
        size_t distance = abs(dx) + abs(dy);

        if(distance < nearestDistance) {
            nearestDistance = distance;
            nearest = *it;
        }
    }

    return nearest;

}

Cell* Field::randomCell() const {
    // FIXME: use c++ random library instead ???
    static bool seeded = false;

    if(!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    return cells.at((int)(rand() / (RAND_MAX + 1.0) * cells.size()));;
}
