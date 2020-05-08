#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "Cell.hpp"
#include "Field.hpp"
#include "Action.hpp"

class Cell;
class Field;
class Action;

class Humanoid {
    const Field& field;
    const Cell& cell;
    const Action* action;
    bool alive;

public:
    Humanoid(const Field& field, const Cell& cell);
    virtual ~Humanoid();
    void setAction(const Field& field) const;
    void executeAction(Field& field);
    bool isAlive() const;
    const Cell& getCell() const;
    const Field& getField() const;
    size_t getX() const;
    size_t getY() const;
};

#endif //BUFFY_HUMANOID_HPP
