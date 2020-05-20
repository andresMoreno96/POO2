#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "Cell.hpp"
#include "Field.hpp"
#include "Action.hpp"
#include "HumanoidType.hpp"

class Cell;
class Field;
class Action;

class Humanoid {
    const Field* field;
    const Action* action;
    const HumanoidType* type;
    Cell* cell;
    Cell* nextPos;
    bool alive;

public:
    Humanoid(const Field& field, const HumanoidType& type);
    virtual ~Humanoid();
    virtual void setAction(const Field& field)=0;
    virtual void executeAction(Field& field)=0;
    bool isAlive() const;
    Cell* getCell() const;
    void setCell(Cell* cell);
    const HumanoidType& getType() const;
    void display() const;
    size_t getX() const;
    size_t getY() const;
    virtual void setNewPosition()=0;

};

#endif //BUFFY_HUMANOID_HPP
