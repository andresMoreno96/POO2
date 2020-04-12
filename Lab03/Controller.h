/*
 * File:   Controller.h
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Bank.h"
#include "Boat.h"
#include "Person.h"
#include "Container.h"
#include "Constraint.h"

#include <vector>

/**
 * Represents a game controller.
 * Processes the player's commands and verifies if his actions are possible.
 */
class Controller {
    
private:
    
    const size_t BOAT_CAPACITY = 2;
    
    bool playing = true;
    unsigned turn = 0;
    
    Bank leftBank, rightBank;
    Boat boat;
    
    const std::vector<const Person*> persons;
    const std::vector<const Constraint*> constraints;
    
public:
    
    /**
     * Creates a new controller.
     * @param persons the list of persons
     * @param constraints the list of constraints
     */
    Controller(const std::vector<const Person*> persons,
               const std::vector<const Constraint*> constraints);
    
    /**
     * Shows the possible commands a player can use.
     */
    void showMenu() const;
    
    /**
     * Displays the current state of the game.
     */
    void display() const;

    /**
     * Resets the game to its stating state.
     */
    void reset();
    
    /**
     * Increments the number of turns.
     */
    void nextTurn();
    
    /**
     * Moves a person to the boat from the boat's bank.
     * Nothing happens if the person isn't on the bank
     * or if the boat is full.
     * The person isn't moved if the constrains are not respected.
     */
    void board(const Person* person);
    
    /**
     * Moves a person from the boat to the boat's bank.
     * Nothing happens if the person isn't on the boat.
     * The person isn't moved if the constrains are not respected.
     */
    void unboard(const Person* person);
    
    /**
     * Moves the boat to the other side of the river
     * if there is a person who can drive on board.
     */
    void moveBoat();
    
    /**
     * Starts the game.
     */
    void play();
    
private:
    
    /**
     * Processes and executes a player's command.
     * @param command the command to execute
     * @param argument the command's argument
     */
    void processCommand(char command, const std::string& argument = "");
    
    /**
     * Moves a person from a container to an other
     * if the constraints are respected.
     * @param person the person to move.
     * @param from starting container
     * @param to destination.
     * @return true if the person has been moved,
     * or false if the person isn't in the starting container or
     * if the constraints aren't satisfied.
     */
    bool movePerson(const Person* person, Container& from, Container& to);
    
    /**
     * Retrieves a person from his name.
     * @param name the name of the person
     * @return the person if found, nullptr otherwise
     */
    const Person* personNamed(const std::string& name);
    
    /**
     * Checks if every constraint is satified in a container.
     * @param container the container to check
     * @return true if the constraints are satified
     */
    bool checkConstraints(const Container& container);
};

#endif	/* CONTROLLER_H */

