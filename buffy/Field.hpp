#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <vector>
#include <list>
#include <memory>
#include "Cell.hpp"
#include "Humanoid.hpp"
#include "HumanoidType.hpp"
#include "Displayable.hpp"

class Cell;
class Humanoid;

class Field : public Displayable {
    static const BuffyType& BUFFY;
    static const HumanType& HUMAN;
    static const VampireType& VAMPIRE;
    size_t turn;
    size_t width;
    size_t height;
    std::vector<Cell*> cells;
    std::list<Humanoid*> humanoids;

public:
    Field(size_t width, size_t height, size_t nbVampires, size_t nbHumans);
    virtual ~Field();
    int nextTurn();
    const Humanoid* nearestFrom(const Humanoid& from, const HumanoidType& type);
    void moveHumanoid(Humanoid& humanoid, Cell& cell);
    void display() const;
    Cell* cellAtPos(size_t x, size_t y) const;

private:
    Cell* randomCell() const;
    void addHumanoid(const HumanoidType& type);
    void displayHorizontalBorder() const;
};

#endif //BUFFY_FIELD_HPP
