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
    static size_t counter;
    const HumanoidType* type;
    Cell* cell;
    bool alive;
    const size_t id;

protected:
    std::unique_ptr<Action> action;

public:
    Humanoid(const HumanoidType& type);
    virtual ~Humanoid();
    virtual void die(Field& field);
    virtual void setAction(const Field& field) = 0;
    void executeAction(Field& field);
    bool isAlive() const;
    Cell* getCell() const;
    void setCell(Cell* cell);
    const HumanoidType& getType() const;
    void display() const;
    int getX() const;
    int getY() const;
    const size_t getId() const;
};

bool operator==(const Humanoid& lhs, const Humanoid& rhs);
bool operator!=(const Humanoid& lhs, const Humanoid& rhs);

#endif //BUFFY_HUMANOID_HPP
