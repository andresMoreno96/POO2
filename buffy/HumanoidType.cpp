//
// Created by simon on 08.05.20.
//

#include "HumanoidType.hpp"

HumanoidType::HumanoidType(const std::string& type) : type(type) {

}

HumanoidType::~HumanoidType() {

}

const std::string& HumanoidType::getType() const {
    return type;
}

bool operator==(const HumanoidType& lhs, const HumanoidType& rhs) {
    return lhs.getType() == rhs.getType();
}

bool operator!=(const HumanoidType& lhs, const HumanoidType& rhs) {
    return !(lhs == rhs);
}