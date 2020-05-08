#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <vector>
#include <list>
#include <memory>
#include "Cell.hpp"
#include "Humanoid.hpp"
#include "HumanoidType.hpp"

class Cell;
class Humanoid;

class Field {
    size_t turn;
    size_t width;
    size_t height;
    std::vector<Cell*> cells;
    std::list<Humanoid*> humanoids;

public:
    Field(size_t width, size_t height);
    virtual ~Field();
    int nextTurn();
    const Humanoid* nearestFrom(const Humanoid& from, const HumanoidType& type);

};

#endif //BUFFY_FIELD_HPP
