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
    const char NEXT = 'n';
    const char STATS = 's';
    const char QUIT = 'q';

    bool playing = true;

    static const BuffyType& BUFFY;
    static const HumanType& HUMAN;
    static const VampireType& VAMPIRE;

    size_t turn =0;
    size_t width;
    size_t height;
    size_t nbHumans;
    size_t nbVampires;

    std::vector<Cell*> cells;
    std::list<Humanoid*> humanoids;

public:
    Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans);
    int nextTurn();
    const Humanoid* nearestFrom(const Humanoid& from, const HumanoidType& type);
    void moveHumanoid(Humanoid& humanoid, Cell& cell);
    void display() const;
    Cell* cellAtPos(size_t x, size_t y) const;
    size_t getWidth() const;
    size_t getHeight() const;
    bool hasVampireLeft() const;
    bool hasHumanLeft() const;
    void play();
    virtual ~Field();

private:
    Cell* randomCell(int random) const;
    void displayHorizontalBorder() const;
    double calculateStats()const;
    void processCommand(char command);

    void createGrid(size_t width, size_t height);
};

#endif //BUFFY_FIELD_HPP
