#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <vector>
#include <list>
#include <random>
#include "Cell.hpp"
#include "Humanoid.hpp"
#include "HumanoidType.hpp"

class Cell;
class Humanoid;

class Field {
    //GAME CONSTANTS
    static const char NEXT = 'n';
    static const char STATS = 's';
    static const char QUIT = 'q';

    static int wins;
    static int totalRounds;

    const size_t initialNbVampires;
    const size_t initialNbHumans;

    bool playing = true;

    size_t turn = 0;
    size_t width;
    size_t height;
    size_t nbHumans = 0;
    size_t nbVampires = 0;

    std::vector<Cell*> cells;
    std::list<Humanoid*> humanoids;

public:
    static const BuffyType& BUFFY;
    static const HumanType& HUMAN;
    static const VampireType& VAMPIRE;

    Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans);
    int nextTurn();
    Humanoid * nearestFrom(const Humanoid *from, const HumanoidType *type) const;
    bool moveHumanoid(Humanoid& humanoid, int coordX, int coordY);
    void display() const;
    void setNbHumans(size_t nbHumans);
    void setNbVampires(size_t nbVampires);
    size_t getNbHumans() const;
    size_t getNbVampires() const;
    bool hasVampireLeft() const;
    bool hasHumanLeft() const;
    double getDistance(const Humanoid *from, const Humanoid* target) const;
    void play();
    void playStats();
    void createHumanoid(const VampireType& type, Cell *cell);
    void createHumanoid(const BuffyType& type, Cell *cell);
    void createHumanoid(const HumanType& type, Cell *cell);
    void addHumanoid(Humanoid* hum, Cell* cell);
    double calculateStats()const;
    virtual ~Field();

private:
    Cell* cellAtPos(size_t x, size_t y) const;
    bool checkBounds(size_t x, size_t y) const;
    void moveHumanoid(Humanoid& humanoid, Cell *cell);
    Cell* randomCell(int random) const;
    void displayHorizontalBorder() const;
    void processCommand(char command);
    void createGrid(size_t width, size_t height);
};

#endif //BUFFY_FIELD_HPP
