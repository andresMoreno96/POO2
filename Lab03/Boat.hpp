/* 
 * File:   Boat.h
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#ifndef BOAT_H
#define	BOAT_H

#include "Container.hpp"
#include "Bank.hpp"

class Boat;

/**
 * Writes informations of the boat to a stream
 * @param stream the stream to write to
 * @param boat the boat
 */
std::ostream& operator<<(std::ostream& stream, const Boat& boat);

/**
 * Represents a boat that can contain a maxed amount of persons.
 */
class Boat : public Container {
    
    const size_t CAPACITY;
    const Bank* _bank;
    
public:

    /**
     * Creates a new boat.
     * @param name the boat's name
     */
    Boat(std::string name, size_t capacity, const Bank* bank);

    virtual void addPerson(const Person* p);
    
    /**
     * Gets the bank where the boat is.
     * @return the boat's bank
     */
    const Bank* bank() const;
    
    /**
     * Checks if the boat is in a bank
     * @param bank the bank to check
     */
    bool isInBank(const Bank* bank) const;

    /**
     * Checks is the boat can change bank.
     * @return true if at leat one person can drive.
     */
    bool canChangeBank() const;
    
    /**
     * Changes the bank of the boak.
     * @param bank the new bank
     */
    void changeBank(const Bank* bank);
    
    /**
     * Checks if the boat has space.
     * @return true if the boat isn't full
     */
    bool hasSpace() const;
};

#endif	/* BOAT_H */

