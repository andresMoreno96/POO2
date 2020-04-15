/*
 * File:   Person.h
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#ifndef PERSON_H
#define	PERSON_H

#include <string>
#include <iostream>
#include <list>

/// The type of a person
enum PersonType {POLICEMAN, THIEF, PARENT, CHILD};

// The sex of a person
enum Sex {MALE, FEMALE};

/**
 * Represents a person with its name, type and sex.
 */
class Person {
    
    const PersonType _type;
    const Sex _sex;
    std::string _name;
    
public:
    
    /**
     * Creates a new person.
     * @param name the name of the person
     * @param type the type of the person
     * @param sex the sex of the person
     */
    Person(const std::string& name, const PersonType type, Sex sex);
    
    /**
     * Returns the name of the person.
     * @return string
     */
    const std::string& name() const;
    
    /**
     * Returns the type of the person.
     * @return PersonType
     */
    PersonType type() const;
    
    /**
     * Returns the sex of the person.
     * @return Sex
     */
    Sex sex() const;
    
    /**
     * Checks if the person is able to drive.
     * @return true if the person can drive, false otherwise
     */
    virtual bool canDrive() const = 0;

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
    Policeman(std::string name, Sex sex);
    
    virtual bool canDrive() const;
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
    Thief(std::string name, Sex sex);
    
    virtual bool canDrive() const;
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
    Parent(std::string name, Sex sex);
    
    virtual bool canDrive() const;
};

/**
 * Represents a Child
 */
class Child : public Person {
    
    const Parent* _father;
    const Parent* _mother;
    
public:
    
    /**
     * Creates a new child.
     * @param name the name of the child
     * @param sex the sex of the child
     * @param father the father of the child
     * @param mother the mother of the child
     */
    Child(std::string name, Sex sex, const Parent* father, const Parent* mother);
    
    /**
     * Returns the father of the child.
     * @return const Parent*
     */
    const Parent* father() const;
    
    /**
     * Returns the mother of the child.
     * @return const Parent*
     */
    const Parent* mother() const;
    
    virtual bool canDrive() const;
};

#endif	/* PERSON_H */

