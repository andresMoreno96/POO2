#ifndef BUFFY_CELL_HPP
#define BUFFY_CELL_HPP

#include <cstddef>
#include <vector>
#include <memory>
#include "Humanoid.hpp"

class Humanoid;

class Cell {
    const size_t X;
    const size_t Y;
    std::vector<const Humanoid*> humanoids;

public:
    Cell(size_t x, size_t y);
    void addCharacter(const Humanoid& character);
    void removeCharacter(const Humanoid& character);
    const std::vector<const Humanoid*>& getHumanoids() const;
    size_t getX() const;
    size_t getY() const;

};

#endif //BUFFY_CELL_HPP
