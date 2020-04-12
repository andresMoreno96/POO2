/*
 * File:   Constraint.h
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 18, 2019
 */

#ifndef Constraint_h
#define Constraint_h

#include "Container.h"

/**
 * Represents a constraint in a container
 */
class Constraint {
    
public:
    
    /// Message of the constraint to display when it fails.
    const std::string MESSAGE;
    
    /**
     * Creates a new contraint.
     * @param message fail message of the constraint
     */
    Constraint(const std::string& message);
    
    /**
     * Verfifies if the constraint is satisfied in a container.
     * @param container the container used to check the constraint
     * @return true if the constraint is satified, false otherwise
     */
    virtual bool check(const Container& container) const = 0;
};

/**
 * Represents a thief constraint which verifies that the thief is
 * with the policeman when there also is a familiy member.
 */
class ThiefConstraint : public Constraint {
    
public:
    
    /**
     * Creates a new thief constraint.
     */
    ThiefConstraint();
    
    bool check(const Container& container) const;
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
    
    bool check(const Container& container) const;
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
    
    bool check(const Container& container) const;
};

#endif /* Constraint_h */
