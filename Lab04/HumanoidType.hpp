/*
 * File:   HumanoidType.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#ifndef BUFFY_HUMANOIDTYPE_HPP
#define BUFFY_HUMANOIDTYPE_HPP

#include <string>

/**
 * Represents a humanoid type
 */
class HumanoidType {
    std::string type;
    const char representation;

public:
    /**
     * Constructor
     * @param type the type name
     * @param representation the character representing this type of humanoid
     */
    HumanoidType(const std::string& type, const char representation);

    /**
     * Destructor
     */
    virtual ~HumanoidType();

    /**
     * Constructor
     * @param humType the type name
     */
    HumanoidType(const HumanoidType& humType);

    /**
     * Get the type's name
     * @return the type
     */
    const std::string& getType() const;

    /**
     * Get the representation
     * @return the char representing this type of humanoid
     */
    char getRepresentation() const;
};

/**
 * Represents the Buffy type
 */
class BuffyType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    /**
     * Constructor
     */
    BuffyType();
};

/**
 * Represents the vampire type
 */
class VampireType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    /**
     * Constructor
     */
    VampireType();
};

/**
 * Represents the human type
 */
class HumanType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    /**
     * Constructor
     */
    HumanType();
};

bool operator==(const HumanoidType& lhs, const HumanoidType& rhs);
bool operator!=(const HumanoidType& lhs, const HumanoidType& rhs);

#endif //BUFFY_HUMANOIDTYPE_HPP
