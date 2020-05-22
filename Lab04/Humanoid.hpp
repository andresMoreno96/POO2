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
    std::unique_ptr<Action> action;
    Cell* cell;
    Cell* nextPos;
    bool alive;

public:
    Humanoid(const HumanoidType& type);
    virtual ~Humanoid();
    virtual void setAction(const Field& field) = 0;
    void executeAction(Field& field);
    bool isAlive() const;
    Cell* getCell() const;
    void setCell(Cell* cell);
    const HumanoidType& getType() const;
    void display() const;
    void setAction(std::unique_ptr<Action> action);
    size_t getX() const;
    size_t getY() const;
    virtual void setNewPosition()=0;

};

#endif //BUFFY_HUMANOID_HPP
