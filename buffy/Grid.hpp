#ifndef BUFFY_GRID_HPP
#define BUFFY_GRID_HPP

#include <cstddef>
#include <vector>
#include <memory>
#include "Cell.hpp"

class Grid {
    size_t width;
    size_t height;
    std::vector<const Cell*> cells;

public:
    Grid(size_t width, size_t height);
    virtual ~Grid();
};

#endif //BUFFY_GRID_HPP
