#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "Cell.hpp"
#include "Field.hpp"
#include "Action.hpp"
#include "HumanoidType.hpp"
#include <memory>

class Cell;
class Field;
class Action;

class Humanoid {
    const HumanoidType* type;
    Cell* cell;
    bool alive;

protected:
    std::unique_ptr<Action> action;

public:
    Humanoid(const HumanoidType& type);
    virtual ~Humanoid();
    virtual void setAction(const Field& field) = 0;
    void executeAction(Field& field);
    bool isAlive() const;
    void setAlive(bool alive);
    Cell* getCell() const;
    void setCell(Cell* cell);
    const HumanoidType& getType() const;
    void display() const;
    int getX() const;
    int getY() const;

};

#endif //BUFFY_HUMANOID_HPP
