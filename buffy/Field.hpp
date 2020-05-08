#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <cstddef>
#include <vector>
#include <list>
#include <memory>
#include "Cell.hpp"

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
};

#endif //BUFFY_FIELD_HPP
