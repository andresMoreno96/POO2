#ifndef BUFFY_MANAGER_HPP
#define BUFFY_MANAGER_HPP

#include "Grid.hpp"

class Manager {
    Grid* grid;
    std::vector<const Vampire*> vampires;
    std::vector<const Human*> humans;
    const Buffy* buffy;

public:
    Manager(size_t gridWidth, size_t gridHeight);
    virtual ~Manager();

    void generateGrid(size_t gridWidth, size_t gridHeight);
    bool hasVampire() const;
    const Person& nearestEnemyFrom(const Buffy& buffy) const;
    const Person& nearestEnemyFrom(const Vampire& vampire) const;
};

#endif //BUFFY_MANAGER_HPP
