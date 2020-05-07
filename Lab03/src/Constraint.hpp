/*
 * File:   Constraint.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#ifndef Constraint_h
#define Constraint_h

#include "Container.hpp"

/**
 * Represents a constraint in a container
 */
class Constraint {
    /// Message of the constraint to display when it fails.
    const std::string MESSAGE;

public:
    
    /**
     * Creates a new contraint.
     * @param message fail message of the constraint
     */
    Constraint(const std::string& message);
    
    /**
     * Verifies if the constraint is satisfied in a container.
     * @param container the container used to check the constraint
     * @return true if the constraint is satisfied, false otherwise
     */
    virtual bool check(const Container& container, const Person* person) const = 0;

    /**
     * Create a copy of a container's persons list and move the person in this new list
     * @param container the container from which to copy the persons list
     * @param person the person to move
     * @return the temporary list
     */
    std::list<const Person* > createTemporaryList(const Container& container, const Person* person) const;

    /**
     * Get the constraint message
     * @return the message
     */
    const std::string& getMessage() const;
};

/**
 * Represents a thief constraint which verifies that the thief is
 * with the policeman when there also is a family member.
 */
class ThiefConstraint : public Constraint {
    
public:
    
    /**
     * Creates a new thief constraint.
     */
    ThiefConstraint();
    
    bool check(const Container& container, const Person* person) const;
};

/**
 * Represents a son constraint which verifies that the son is
 * with his father when there also is his mother.
 */
class SonConstraint : public Constraint {
    
public:
    
    /**
     * Creates a new son constraint.
     */
    SonConstraint();
    
    bool check(const Container& container, const Person* person) const;
};

/**
 * Represents a daughter constraint which verifies that the dauther is
 * with her mother when there also is her father.
 */
class DaughterConstraint : public Constraint {
    
public:
    
    /**
     * Creates a new daughter constraint.
     */
    DaughterConstraint();
    
    bool check(const Container& container, const Person* person) const;
};

#endif /* Constraint_h */
