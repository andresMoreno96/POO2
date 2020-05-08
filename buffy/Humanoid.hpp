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
    static size_t humanoidCounter;
    size_t id;
    const Field* field;
    const Action* action;
    const HumanoidType* type;
    Cell* cell;
    bool alive;

public:
    Humanoid(const Field& field, const HumanoidType& type);
    virtual ~Humanoid();
    void setAction(const Field& field) const;
    void executeAction(Field& field);
    bool isAlive() const;
    Cell* getCell() const;
    void setCell(Cell* cell);
    const Field* getField() const;
    const HumanoidType& getType() const;
    size_t getX() const;
    size_t getY() const;
    size_t getId() const;
};

bool operator==(const Humanoid& lhs, const Humanoid& rhs);
bool operator!=(const Humanoid& lhs, const Humanoid& rhs);

#endif //BUFFY_HUMANOID_HPP
