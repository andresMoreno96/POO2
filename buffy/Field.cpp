//
// Created by simon on 07.05.20.
//

#include "Field.hpp"

using namespace std;

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

Field::Field(size_t width, size_t height) {
    // TODO: implement this
}

Field::~Field() {
    // TODO: implement this
}
