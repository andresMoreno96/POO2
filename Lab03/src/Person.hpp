/*
 * File:   Person.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include "Role.hpp"

// The sex of a person
enum Sex {
    MALE, FEMALE
};

/**
 * Represents a person with its name, type and sex.
 */
class Person {

    const std::vector<const Role *> &roles;
    const Sex _sex;
    std::string _name;

public:
    /***
     * checks if the current person has the given role
     * @param role the role of the person
     * @return true if the person has that role
     */
    bool hasRole(const std::string &role) const;

    /**
     * Creates a new person.
     * @param name the name of the person
     * @param type the type of the person
     * @param sex the sex of the person
     */
    Person(const std::string &name, Sex sex,
           const std::vector<const Role *> &roles);

    /**
     * Returns the name of the person.
     * @return string
     */
    const std::string &name() const;

    /**
     * Returns the sex of the person.
     * @return Sex
     */
    Sex sex() const;

    virtual ~Person();
};

/**
 * Represents a policeman
 */
class Policeman : public Person {
public:

    /**
     * Creates a new policeman.
     * @param name the name of the policeman
     * @param sex the sex of the policeman
     */
    Policeman(std::string name, Sex sex, const std::vector<const Role *> &roles);
};

/**
 * Represents a Thief
 */
class Thief : public Person {
public:

    /**
     * Creates a new thief.
     * @param name the name of the thief
     * @param sex the sex of the thief
     */
    Thief(std::string name, Sex sex, const std::vector<const Role *> &roles);
};

/**
 * Represents a Parent
 */
class Parent : public Person {
public:

    /**
     * Creates a new parent.
     * @param name the name of the parent
     * @param sex the sex of the parent
     */
    Parent(std::string name, Sex sex, const std::vector<const Role *> &roles);
};

/**
 * Represents a Child
 */
class Child : public Person {

    const Parent *_father;
    const Parent *_mother;

public:

    /**
     * Creates a new child.
     * @param name the name of the child
     * @param sex the sex of the child
     * @param father the father of the child
     * @param mother the mother of the child
     */
    Child(std::string name, Sex sex, const Parent *father,
          const Parent *mother, const std::vector<const Role *> &roles);

    /**
     * Returns the father of the child.
     * @return const Parent*
     */
    const Parent *father() const;

    /**
     * Returns the mother of the child.
     * @return const Parent*
     */
    const Parent *mother() const;
};

#endif    /* PERSON_H */

