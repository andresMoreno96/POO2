#ifndef BUFFY_CELL_HPP
#define BUFFY_CELL_HPP

#include <cstddef>
#include <vector>
#include <memory>
#include "Person.hpp"

class Person;

class Cell {
    const size_t X;
    const size_t Y;
    std::vector<const Person*> characters;

public:
    Cell(size_t x, size_t y);
    void addCharacter(const Person& character);
    void removeCharacter(const Person& character);
    const std::vector<const Person*>& getCharacters() const;
    size_t getX() const;
    size_t getY() const;

};

#endif //BUFFY_CELL_HPP
