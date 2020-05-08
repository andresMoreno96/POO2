#ifndef BUFFY_HUMANOIDTYPE_HPP
#define BUFFY_HUMANOIDTYPE_HPP

#include <string>

class HumanoidType {
    std::string type;

public:
    HumanoidType(const std::string& type);
    virtual ~HumanoidType();
    const std::string& getType() const;
};

#endif //BUFFY_HUMANOIDTYPE_HPP
