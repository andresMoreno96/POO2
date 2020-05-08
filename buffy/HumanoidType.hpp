#ifndef BUFFY_HUMANOIDTYPE_HPP
#define BUFFY_HUMANOIDTYPE_HPP

#include <string>

class HumanoidType {
    std::string type;
    const char representation;

public:
    HumanoidType(const std::string& type, const char representation);
    const std::string& getType() const;
    char getRepresentation() const;
};

class BuffyType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    BuffyType();
};

class VampireType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    VampireType();
};

class HumanType : public HumanoidType {
    static const std::string type;
    static const char representation;
public:
    HumanType();
};

bool operator==(const HumanoidType& lhs, const HumanoidType& rhs);
bool operator!=(const HumanoidType& lhs, const HumanoidType& rhs);

#endif //BUFFY_HUMANOIDTYPE_HPP
