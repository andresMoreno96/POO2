/*
 * File:   Constraint.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 10, 2020
 */

#include <algorithm>
#include "Constraint.hpp"
#include "Container.hpp"
#include "Person.hpp"

Constraint::Constraint(const std::string &message) : MESSAGE(message) {}

std::list<const Person *> Constraint::createTemporaryList(const Container &container, const Person *person) const {
    std::list<const Person *> tmp;

    for (const Person *p : container.persons()) {

        tmp.push_back(p);
    }

    if (container.contains(person)) { //from
        tmp.remove(person);
    } else { //to
        tmp.push_back(person);
    }


    return tmp;
}

ThiefConstraint::ThiefConstraint()
        : Constraint("voleur avec un membre de la famille sans le policier") {}

bool ThiefConstraint::check(const Container &container, const Person *person) const {

    std::list<const Person *> tmp = createTemporaryList(container, person);

    return !(container.contains(tmp, [](const Person *p) {
        return p->hasRole("THIEF");
    }) && (container.contains(tmp, [](const Person *p) {
        return p->hasRole("PARENT") || p->hasRole("CHILD");
    })) && !(container.contains(tmp, [](const Person *p) {
        return p->hasRole("POLICEMAN");
    })));


}


SonConstraint::SonConstraint() : Constraint("garcon avec sa mere sans son pere") {}

bool SonConstraint::check(const Container &container, const Person *person) const {

    std::list<const Person *> tmp = createTemporaryList(container, person);

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        if ((*it)->hasRole("CHILD") && (*it)->sex() == MALE) {

            const Child *son = (const Child *) *it;

            if ((find(tmp.begin(), tmp.end(), son->mother()) != tmp.end()) &&
                !(find(tmp.begin(), tmp.end(), son->father()) != tmp.end())) {


                return false;
            }

            if (container.contains(son->mother())
                && !container.contains(son->father())) {

                return false;
            }
        }
    }
    return true;

}

DaughterConstraint::DaughterConstraint()
        : Constraint("fille avec son pere sans sa mere") {}

bool DaughterConstraint::check(const Container &container, const Person *person) const {


    std::list<const Person *> tmp = createTemporaryList(container, person);

    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        if ((*it)->hasRole("CHILD") && (*it)->sex() == FEMALE) {

            const Child *son = (const Child *) *it;

            if (!(find(tmp.begin(), tmp.end(), son->mother()) != tmp.end()) &&
                (find(tmp.begin(), tmp.end(), son->father()) != tmp.end())) {
                return false;
            }

            if (!container.contains(son->mother())
                && container.contains(son->father())) {

                return false;
            }
        }
    }
    return true;

}
