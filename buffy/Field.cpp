#include "Field.hpp"
#include <time.h>

using namespace std;

const HumanoidType& Field::BUFFY   = HumanoidType("buffy");
const HumanoidType& Field::HUMAN   = HumanoidType("human");
const HumanoidType& Field::VAMPIRE = HumanoidType("vampire");

Field::Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans) {
    // TODO: implement this

    // Générer la grille
    for(size_t y = 0; y < height; ++y) {
        for(size_t x = 0; x < width; ++x) {
            cells.push_back(new Cell(x, y));
        }
    }

    // Créer les humanoids

    // Créer Buffy
    addHumanoid(BUFFY);

    // Créer les humains
    for(size_t human = 1; human < nbHumans; ++human) {
        addHumanoid(HUMAN);
    }

    // Créer les vampires
    for(size_t vampire = 0; vampire < nbVampires; ++vampire) {
        addHumanoid(VAMPIRE);
    }

}

Field::~Field() {
    // TODO: implement this

    for(size_t i = 0; i < cells.size(); ++i) {
        delete cells.at(i);
    }

    // Delete humanoids
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); ++it) {
        it = humanoids.erase(it); // suppression de l’élément dans la liste
        delete *it;
    }
}

void Field::addHumanoid(const HumanoidType& type) {
    Cell* cell = randomCell();
    Humanoid* humanoid = new Humanoid(*this, type);

    humanoids.push_back(humanoid);
    moveHumanoid(*humanoid, *cell);
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

void Field::moveHumanoid(Humanoid& humanoid, Cell& cell) {
    Cell* currentCell = humanoid.getCell();

    if(currentCell != nullptr) {
        currentCell->removeHumanoid(humanoid);
    }

    humanoid.setCell(&cell);
}
