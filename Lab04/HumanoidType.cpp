//
// Created by simon on 08.05.20.
//

#include "HumanoidType.hpp"

using namespace std;

const string BuffyType::type   = "buffy";
const string VampireType::type = "vampire";
const string HumanType::type   = "human";
const char BuffyType::representation = 'B';
const char VampireType::representation = 'v';
const char HumanType::representation   = 'h';

HumanoidType::HumanoidType(const string& type, char representation) : type(type), representation(representation) {

}

const std::string& HumanoidType::getType() const {
    return type;
}

char HumanoidType::getRepresentation() const {
    return representation;
}

BuffyType::BuffyType() : HumanoidType(BuffyType::type, BuffyType::representation) {

}

VampireType::VampireType() : HumanoidType(VampireType::type, VampireType::representation) {

}

HumanType::HumanType() : HumanoidType(HumanType::type, HumanType::representation) {

}

bool operator==(const HumanoidType& lhs, const HumanoidType& rhs) {
    return lhs.getType() == rhs.getType();
}

bool operator!=(const HumanoidType& lhs, const HumanoidType& rhs) {
    return !(lhs == rhs);
}