//
// Created by Andres Moreno on 15.04.20.
//

#include "Role.hpp"
Role::Role(const std::string &role) : _role(role) {}

Role::~Role() {}

const std::string &Role::getRole() const {
    return _role;
}

PolicemanRole::PolicemanRole() : Role("POLICEMAN") {}

ThieveRole::ThieveRole() : Role("THIEF") {}

DriveRole::DriveRole() : Role("DRIVE") {}

ChildRole::ChildRole() : Role("CHILD") {}

ParentRole::ParentRole() : Role("PARENT") {}




