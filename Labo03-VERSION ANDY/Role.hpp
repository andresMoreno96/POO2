//
// Created by Andres Moreno on 15.04.20.
//

#ifndef LAB03_ROLE_HPP
#define LAB03_ROLE_HPP

#include <string>
#include <iostream>
#include <list>

class Role {

private:
    std::string _role;

public:

    Role(const std::string &role);

    virtual const std::string &getRole() const;

    virtual ~Role();

};


class PolicemanRole : public Role {

public:

    PolicemanRole();

};

class ThieveRole : public Role {

public:
    ThieveRole();
};

class ParentRole : public Role {
public:
    ParentRole();
};

class ChildRole : public Role {
public:
    ChildRole();
};

class DriveRole : public Role {
public:
    DriveRole();

};


#endif //LAB03_ROLE_HPP
