#include "Field.hpp"
#include "Buffy.hpp"
#include "Human.hpp"
#include "Vampire.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

using namespace std;

const BuffyType &Field::BUFFY = BuffyType();
const VampireType &Field::VAMPIRE = VampireType();
const HumanType &Field::HUMAN = HumanType();


Field::Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans) : width(width), height(height),
                                                                                nbVampires(nbVampires),
                                                                                nbHumans(nbHumans) {
    // Générer la grille
    createGrid(width, height);

    //for random placement
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, cells.size() - 1);

    // Créer les humanoids

    // Créer Buffy
    Buffy *buffy = new Buffy(*this, BUFFY);
    humanoids.push_back(buffy);
    moveHumanoid(*buffy, *randomCell(distribution(rd)));

    // Créer les humains
    vector<Human *> humans;
    for (size_t human = 0; human < nbHumans; ++human) {
        humans.push_back(new Human(*this, HUMAN));
    }
    for (auto &it: humans) {
        humanoids.push_back(it);
        moveHumanoid(*it, *randomCell(distribution(rd)));
    }

    // Créer les vampires
    vector<Vampire *> vampires;
    for (size_t vampire = 0; vampire < nbVampires; ++vampire) {
        vampires.push_back(new Vampire(*this, VAMPIRE));
    }

    for (auto &it: vampires) {
        humanoids.push_back(it);
        moveHumanoid(*it, *randomCell(distribution(rd)));
    }

}


void Field::createGrid(size_t width, size_t height) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            cells.push_back(new Cell(x, y));
        }
    }
}


int Field::nextTurn() {
    // NOTE: ne pas changer cette méthode, elle est tirée de la donnée !

    // Déterminer les prochaines actions
    for (auto it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);

    // Executer les actions
    for (auto it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);

    // Enlever les humanoides tués
    for (auto it = humanoids.begin(); it != humanoids.end();)
        if (!(*it)->isAlive()) {
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it;
            // destruction de l’humanoide référencé
        } else
            ++it;

    return turn++;
}

const Humanoid *Field::nearestFrom(const Humanoid &from, const HumanoidType &type) {
    size_t nearestDistance = -1; // -1 vas passer au max de size_t
    const Humanoid *nearest = nullptr;

    for (auto it = humanoids.begin(); it != humanoids.end(); ++it) {
        if ((*it)->getType() != type) {
            continue;
        }

        int dx = from.getX() - (*it)->getX();
        int dy = from.getY() - (*it)->getY();
        size_t distance = abs(dx) + abs(dy);

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

void Field::moveHumanoid(Humanoid &humanoid, Cell &cell) {
    Cell *currentCell = humanoid.getCell();

    if (currentCell != nullptr) {
        currentCell->removeHumanoid(humanoid);
    }

    humanoid.setCell(&cell);
    cell.addHumanoid(humanoid);
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

Cell *Field::cellAtPos(size_t x, size_t y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw new out_of_range("This cell position is out of range.");
    }

    return cells.at(x + width * y);
}


void Field::processCommand(char command) {

    if (command == NEXT) {
        nextTurn();
    } else if (command == STATS) {
        calculateStats();
    } else if (command == QUIT) {
        playing = false;
    } else {
        cout << "### entrée invalide" << endl;
    }

}

void Field::play() {

    string input;
    bool displayGrid=false;
    cout<< "Want to display the gird? (y/n)"<<endl;

    getline(cin, input, '\n');

    //FIXME:check invalid input
    if (input.size() > 0) {
        char command = input[0];
        if(command=='y'){
            displayGrid= true;
        }
    }
    cout << endl;

    input="";
    while (playing) {

        if(displayGrid){
            display();
        }

        cout << "[" << turn << "]" << " q)quit s)statistics n)nextTurn: ";

        getline(cin, input, '\n');
        if (input.size() > 0) {
            char command = input[0];
            processCommand(command);
        }
    }
}

double Field::calculateStats() const {
    return 0;
}


Field::~Field() {
    // TODO: implement this

    for (size_t i = 0; i < cells.size(); ++i) {
        delete cells.at(i);
    }

    // Delete humanoids
    for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end(); ++it) {
        it = humanoids.erase(it); // suppression de l’élément dans la liste
        delete *it;
    }
}

size_t Field::getWidth() const {
    return width;
}

size_t Field::getHeight() const {
    return height;
}

