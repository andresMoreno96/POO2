/*
 * File:   Container.hpp
 * Author: Andres Moreno, Simon walther
 *
 * Created on May 13, 2020
 */

#ifndef CONTAINER_H
#define	CONTAINER_H

#include <string>
#include <list>
#include <functional>

#include "Person.hpp"

class Container;

/**
 * Writes informations of the container to a stream
 * @param stream the stream to write to
 * @param container the container
 */
std::ostream& operator<<(std::ostream& stream, const Container& container);

/**
 * Represents a container that can contains persons.
 */
class Container {
    
    std::string _name;
    std::list<const Person*> _persons;
    
public:
    
    /**
     * Creates a new container.
     * @param name the name of the container
     */
    Container(std::string name);

    /**
     * Adds a person to the container
     * @param p person to add
     */
    virtual void addPerson(const Person* p);
    
    /**
     * Removes a person from the container
     * @param p person to remove
     */
    virtual void removePerson(const Person* p);


    /**
     * Gets the count of persons in the container.
     * @return size_t
     */
    size_t personsCount() const;
    
    /**
     * Gets the name of the container.
     * @return string
     */
    std::string name() const;

    /**
     * Gets the list of persons in the container.
     * @return list
     */
    const std::list<const Person*>& persons() const;
    
    /**
     * Checks if at least one person in the container
     * verifies a function
     * @param f function to verify
     * @return true if at least one person verifies the function
     */
    bool contains(std::function<bool(const Person*)> f) const;


    /***
     * Checks if at least one person in the container
     * verifies a function
     * @param persons list of persons
     * @param f function to verify
     * @return true if at least one person verifies the function
     */
    bool contains(std::list<const Person *> persons, std::function<bool(const Person *)> f) const;
    
    /**
     * Checks if a person is in the container
     * @param person the person to search
     * @return true if the person is in the container
     */
    bool contains(const Person* person) const;
    
    /**
     * Empties the container.
     */
    void empty();
};

#endif	/* CONTAINER_H */

