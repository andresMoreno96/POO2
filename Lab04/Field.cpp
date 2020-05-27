#include "Field.hpp"
#include "Buffy.hpp"
#include "Human.hpp"
#include "Vampire.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <cmath>

using namespace std;

const BuffyType &Field::BUFFY = BuffyType();
const VampireType &Field::VAMPIRE = VampireType();
const HumanType &Field::HUMAN = HumanType();

int Field::wins=0;
int Field::totalRounds=10000;

Field::Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans) : width(width), height(height),
                                                                                initialNbVampires(nbVampires),
                                                                                initialNbHumans(nbHumans) {
    // Générer la grille
    createGrid(width, height);

    //for random placement
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, cells.size() - 1);

    // Créer les humanoids
    // Créer Buffy
    createHumanoid(Field::BUFFY, randomCell(distribution(rd)));

    // Créer les vampires
    for (size_t vampire = 0; vampire < nbVampires; ++vampire) {
        createHumanoid(Field::VAMPIRE, randomCell(distribution(rd)));
    }

    // Créer les humains
    for (size_t human = 0; human < nbHumans; ++human) {
        createHumanoid(Field::HUMAN, randomCell(distribution(rd)));
    }
}


void Field::createGrid(size_t width, size_t height) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            cells.push_back(new Cell(x, y));
        }
    }
}

// NOTE: ne pas changer cette méthode, elle est tirée de la donnée !
int Field::nextTurn() {
    // Déterminer les prochaines actions
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);

    // Executer les actions
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);

    // Enlever les humanoides tués
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); )
        if (!(*it)->isAlive()) {
            delete *it; // destruction de l’humanoide référencé
            it = humanoids.erase(it); // suppression de l’élément dans la liste
        }
        else
            ++it;

    return turn++;
}

double Field::getDistance(const Humanoid *from, const Humanoid* target) const {
    int dx= target->getX() - from->getX();
    int dy= target->getY() - from->getY();

    return abs(sqrt(pow(dx,2)+pow(dy,2)));

}

Humanoid * Field::nearestFrom(const Humanoid *from, const HumanoidType *type) const {
    double nearestDistance = numeric_limits<double>::max();
    Humanoid *nearest = nullptr;

    for (auto it = humanoids.begin(); it != humanoids.end(); ++it) {
        if ((*it)->getType() != *type) {
            continue;
        }

        double distance = getDistance(from, *it);

        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearest = *it;
        }
    }

    return nearest;
}


Cell *Field::randomCell(int random) const {
    return cells.at(random);
}

bool Field::moveHumanoid(Humanoid &humanoid, int coordX, int coordY) {

    if (!checkBounds(coordX, coordY)) {
        return false;
    }

    moveHumanoid(humanoid, cellAtPos(coordX, coordY));
    return true;

}

void Field::moveHumanoid(Humanoid &humanoid, Cell *cell) {

    Cell *currentCell = humanoid.getCell();

    if (currentCell != nullptr) {
        currentCell->removeHumanoid(humanoid);
    }

    humanoid.setCell(cell);
    cell->addHumanoid(humanoid);
}

void Field::display() const {
    displayHorizontalBorder();

    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            if (x == 0) {
                cout << "| ";
            }

            cellAtPos(x, y)->display();
            cout << ' ';

            if (x == (width - 1)) {
                cout << "|";
            }
        }
        cout << endl;
    }

    displayHorizontalBorder();
}

void Field::displayHorizontalBorder() const {// Afficher barre horizontale
    cout << setw(width * 2 + 2) << setfill('-') << left << "+" << "+" << endl;
}

bool Field::checkBounds(size_t x, size_t y) const {
    return (x < width && y < height);
}

Cell *Field::cellAtPos(size_t x, size_t y) const {
    return cells.at(x + width * y);
}

void Field::processCommand(char command) {

    if (command == NEXT) {
        nextTurn();
    } else if (command == STATS) {
        cout<<"Calculating stats..."<<endl;
        wins=0;
        double simulation=calculateStats();
        cout<<"simulation % : "<<simulation<<endl;
    } else if (command == QUIT) {
        playing = false;
    } else {
        cout << "### entrée invalide" << endl;
    }

}

void Field::play() {

    string input = "";
    cout << endl;

    while (playing) {
        display();
        cout << "[" << turn << "]" << " q)quit s)statistics n)nextTurn: ";

        getline(cin, input, '\n');
        if (input.size() > 0) {
            char command = input[0];
            processCommand(command);
        }
    }
}

void Field::playStats(){
    while (playing){
        processCommand('n');
        if(hasHumanLeft() && !hasVampireLeft()){
            wins++;
        }
        if(!hasVampireLeft()){
            playing=false;
        }
    }

}


double Field::calculateStats() const {
    for(size_t i=0; i < totalRounds; ++i){
        Field tmp(width,height,initialNbVampires,initialNbHumans);
        tmp.playStats();
    }

    return ((double)wins / ((double)totalRounds)) * 100.0;
}

Field::~Field() {
    for (size_t i = 0; i < cells.size(); ++i) {
        delete cells.at(i);
    }

    // Delete humanoids
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); ++it) {
        delete *it;
        it = humanoids.erase(it);

    }
}

void Field::createHumanoid(const BuffyType& type, Cell *cell) {
    Buffy* buffy = new Buffy();
    addHumanoid(buffy, cell);
}

void Field::createHumanoid(const VampireType& type, Cell *cell) {
    Vampire* vampire = new Vampire();
    ++nbVampires;
    addHumanoid(vampire, cell);
}

void Field::createHumanoid(const HumanType& type, Cell *cell) {
    Human* human = new Human();
    ++nbHumans;
    addHumanoid(human, cell);
}

void Field::addHumanoid(Humanoid *hum, Cell *cell) {
    humanoids.push_back(hum);
    moveHumanoid(*hum, cell);
}

bool Field::hasVampireLeft() const {
    return nbVampires > 0;
}

bool Field::hasHumanLeft() const {
    return nbHumans > 0;
}

void Field::setNbHumans(size_t nbHumans) {
    this->nbHumans = nbHumans;
}

void Field::setNbVampires(size_t nbVampires) {
    this->nbVampires = nbVampires;
}

size_t Field::getNbHumans() const {
    return nbHumans;
}

size_t Field::getNbVampires() const {
    return nbVampires;
}
