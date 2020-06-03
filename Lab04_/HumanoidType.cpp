/*
 * File:   HumanoidType.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on May 7, 2020
 */

#include "HumanoidType.hpp"

using namespace std;

const string BuffyType::type = "buffy";
const string VampireType::type = "vampire";
const string HumanType::type = "human";
const char BuffyType::representation = 'B';
const char VampireType::representation = 'v';
const char HumanType::representation = 'h';

HumanoidType::HumanoidType(const string &type, char representation) : type(type), representation(representation) {

}

HumanoidType::HumanoidType(const HumanoidType &humType) : representation(humType.representation), type(humType.type) {

}

const std::string &HumanoidType::getType() const {
    return type;
}

char HumanoidType::getRepresentation() const {
    return representation;
}

HumanoidType::~HumanoidType() {

}

BuffyType::BuffyType() : HumanoidType("buffy", BuffyType::representation) {

}

VampireType::VampireType() : HumanoidType("vampire", VampireType::representation) {

}

HumanType::HumanType() : HumanoidType("human", HumanType::representation) {

}

bool operator==(const HumanoidType &lhs, const HumanoidType &rhs) {
    return lhs.getType() == rhs.getType();
}

bool operator!=(const HumanoidType &lhs, const HumanoidType &rhs) {
    return !(lhs == rhs);
}