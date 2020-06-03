/*
 * File:   Field.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <vector>
#include <list>
#include <random>
#include "Cell.hpp"
#include "Humanoid.hpp"
#include "HumanoidType.hpp"

class Cell;

class Humanoid;

/**
 * Represents a field and manage the "game"
 */
class Field {
    // GAME CONSTANTS
    static const char NEXT = 'n';
    static const char STATS = 's';
    static const char QUIT = 'q';

    static int wins;
    static int totalRounds;

    const size_t initialNbVampires;
    const size_t initialNbHumans;

    bool playing = true;

    size_t turn = 0;
    size_t width;
    size_t height;
    size_t nbHumans = 0;
    size_t nbVampires = 0;

    std::vector<Cell *> cells;
    std::list<Humanoid *> humanoids;

public:
    static const BuffyType &BUFFY;
    static const HumanType &HUMAN;
    static const VampireType &VAMPIRE;

    /**
     * Constructor
     * @param width the field's width
     * @param height the field's height
     * @param initialNbVampires the initial number of vampires
     * @param initialNbHumans the initial number of humans
     */
    Field(size_t width, size_t height, size_t initialNbVampires, size_t initialNbHumans);

    /**
     * Destructor
     */
    virtual ~Field();

    /**
     * Make a turn, all humanoids does their actions and dead humanoids are removed
     * @return the turn number
     */
    int nextTurn();

    /**
     * Get the nearest humanoid of a certain type from another humanoid
     * @param from the humanoid from which to search
     * @param type the type of the desired nearest humanoid
     * @return the nearest humanoid
     */
    Humanoid *nearestFrom(const Humanoid *from, const HumanoidType *type) const;

    /**
     * Move a humanoid to a given coordinate
     * @param humanoid the humanoid to move
     * @param coordX the x coordinate
     * @param coordY the y coordinate
     * @return if the move has succeeded
     */
    bool moveHumanoid(Humanoid &humanoid, int coordX, int coordY);

    /**
     * Display the field
     */
    void display() const;

    /**
     * Set the number of humans
     * @param nbHumans the new number
     */
    void setNbHumans(size_t nbHumans);

    /**
     * Set the number of vampires
     * @param nbVampires the new number
     */
    void setNbVampires(size_t nbVampires);

    /**
     * Get the number of humans
     * @return the number
     */
    size_t getNbHumans() const;

    /**
     * Get the number of vampires
     * @return the number
     */
    size_t getNbVampires() const;

    /**
     * Get if there is any vampire left
     * @return if there is any vampire left
     */
    bool hasVampireLeft() const;

    /**
     * Get if there is any human left
     * @return if there is any human left
     */
    bool hasHumanLeft() const;

    /**
     * Get the distance between two humanoids
     * @param first the first humanoid
     * @param second the second humanoid
     * @return the distance
     */
    double getDistance(const Humanoid *first, const Humanoid *second) const;

    /**
     * Play the "game", prompting the user for action
     */
    void play();

    /**
     * Play a game and calculates its stats
     */
    void playStats();

    /**
     * Create a humanoid of vampire type and moves it to a given cell
     * @param type the type of the humanoid
     * @param cell the cell where to creates the humanoid
     */
    void createHumanoid(const VampireType &type, Cell *cell);

    /**
     * Create a humanoid of buffy type and moves it to a given cell
     * @param type the type of the humanoid
     * @param cell the cell where to creates the humanoid
     */
    void createHumanoid(const BuffyType &type, Cell *cell);

    /**
     * Create a humanoid of human type and moves it to a given cell
     * @param type the type of the humanoid
     * @param cell the cell where to creates the humanoid
     */
    void createHumanoid(const HumanType &type, Cell *cell);

    /**
     * Add an existing humanoid to the field at a given cell
     * @param hum the humanoid
     * @param cell the cell where to put the humanoid
     */
    void addHumanoid(Humanoid *hum, Cell *cell);

    /**
     * Calculates stats with this field properties
     * @return the wins ratio
     */
    double calculateStats() const;

private:
    /**
     * Get the field's cell at a given position
     * @param x the x coordinate
     * @param y the y coordinate
     * @return the cell
     */
    Cell *cellAtPos(size_t x, size_t y) const;

    /**
     * Check if a coordinates is inside the field's bounds
     * @param x the x coordinates
     * @param y the y coordinates
     * @return if a coordinates is inside the field's bounds
     */
    bool checkBounds(size_t x, size_t y) const;

    /**
     * Move humanoid the a given cell
     * @param humanoid the humanoid to move
     * @param cell the cell on which to put the humanoid
     */
    void moveHumanoid(Humanoid &humanoid, Cell *cell);

    /**
     * Get a random cell of this field
     * @return the cell
     */
    Cell *randomCell() const;

    /**
     * Display an horizontal bar
     */
    void displayHorizontalBorder() const;

    /**
     * Process user's commands
     * @param command the command to process
     */
    void processCommand(char command);

    /**
     * Create a grid of a given width and height
     * @param width the width
     * @param height the height
     */
    void createGrid(size_t width, size_t height);
};

#endif //BUFFY_FIELD_HPP
