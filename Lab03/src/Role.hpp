/*
 * File:   Role.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 15, 2020
 */

#ifndef LAB03_ROLE_HPP
#define LAB03_ROLE_HPP

#include <string>
#include <iostream>
#include <list>

/**
 * Represents a person's role
 */
class Role {

private:
    std::string _role;

public:

    /**
     * Creates a new role
     * @param role the role name
     */
    Role(const std::string &role);

    /**
     * Destructs the role
     */
    virtual ~Role();

    /**
     * Get the role
     * @return the role name
     */
    virtual const std::string &getRole() const;

};

/**
 * Represents the policeman role
 */
class PolicemanRole : public Role {

public:
    /**
     * Creates a new policeman role
     */
    PolicemanRole();
};

/**
 * Represents the thieve role
 */
class ThieveRole : public Role {

public:
    /**
     * Creates a new thieve role
     */
    ThieveRole();
};

/**
 * Represents the parent role
 */
class ParentRole : public Role {

public:
    /**
     * Creates a new parent role
     */
    ParentRole();
};

/**
 * Represents the child role
 */
class ChildRole : public Role {

public:
    /**
     * Creates a new child role
     */
    ChildRole();
};

/**
 * Represents the driver role
 */
class DriveRole : public Role {

public:
    /**
     * Creates a new drive role
     */
    DriveRole();

};


#endif //LAB03_ROLE_HPP
