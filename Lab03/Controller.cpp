/*
 * File:   Controller.cpp
 * Author: Nohan Budry, Andres Moreno
 *
 * Created on May 9, 2019
 */

#include <iostream>
#include <string>

#include "Controller.h"
#include "Person.h"
#include "Container.h"
#include "Constraint.h"

using namespace std;

Controller::Controller(const std::vector<const Person*> persons,
                       const std::vector<const Constraint*> constraints)
: persons(persons), constraints(constraints), leftBank("Gauche"),
rightBank("Droite"), boat("Bateau", BOAT_CAPACITY, &leftBank) {
    
    reset();
}

void Controller::showMenu() const {
    cout << "p      : afficher" << endl;
    cout << "e <nom>: embarquer <nom>" << endl;
    cout << "d <nom>: debarquer <nom>" << endl;
    cout << "m      : deplacer bateau" << endl;
    cout << "r      : reinitialiser" << endl;
    cout << "q      : quitter" << endl;
    cout << "h      : menu" << endl;
}

void Controller::display() const {
    static int SIZE = 80;
    cout << string(SIZE, '-') << endl;
    cout << leftBank << endl;
    cout << string(SIZE, '-') << endl;
    boat.isInBank(&leftBank) ? cout << boat << endl : cout << endl;
    cout << string(SIZE, '=') << endl;
    boat.isInBank(&rightBank) ? cout << boat << endl : cout << endl;
    cout << string(SIZE, '-') << endl;
    cout << rightBank << endl;
    cout << string(SIZE, '-') << endl;
}

void Controller::reset() {
    turn = 0;
    
    leftBank.empty();
    rightBank.empty();
    boat.empty();
    
    for (const Person* person : persons) {
        leftBank.addPerson(person);
    }
}

void Controller::nextTurn() {
    ++turn;
}

void Controller::board(const Person* person) {
    
    nextTurn();
    
    Bank& bank = boat.bank() == &leftBank ? leftBank : rightBank;
    if (boat.hasSpace() && bank.contains(person)
        && movePerson(person, bank, boat)) {
        
        display();
    }
}

void Controller::unboard(const Person* person) {
    
    nextTurn();
    
    Bank& bank = boat.bank() == &leftBank ? leftBank : rightBank;
    if (boat.contains(person) && movePerson(person, boat, bank)) {
        display();
    }
}

void Controller::moveBoat() {
    
    nextTurn();
    
    if (boat.canChangeBank()) {
        Bank* bank = boat.bank() == &leftBank ? &rightBank : &leftBank;
        boat.changeBank(bank);
        
        display();
    }
}

bool Controller::movePerson(const Person* person,
                            Container& from, Container& to) {
    
    from.removePerson(person);
    to.addPerson(person);
    
    if (!checkConstraints(from) || !checkConstraints(to)) {
        to.removePerson(person);
        from.addPerson(person);
        return false;
    }
    
    return true;
}

void Controller::play() {
    
    showMenu();
    cout << endl;
    display();
    
    string input;
    while (playing) {
        
        cout << turn << "> ";
        
        getline(cin, input, '\n');
        if (input.size() > 0) {
            
            size_t index = input.find(' ');
            if (index == string::npos) {
                processCommand(input[0]);
                
            } else {
                char command = input[0];
                string argument = input.substr(index + 1, input.length());
                processCommand(command, argument);
            }
        }
    }
}

void Controller::processCommand(char command, const std::string& argument) {
    
    const Person* person = personNamed(argument);
    
    switch (command) {
            break;
        case 'p':
            display();
            break;
        case 'e':
            if (person != nullptr) {
                board(person);
            } else {
                std::cout << "### Unknown person." << std::endl;
            }
            break;
        case 'd':
            if (person != nullptr) {
                unboard(person);
            } else {
                std::cout << "### Unknown person." << std::endl;
            }
            break;
        case 'm':
            moveBoat();
            break;
        case 'r':
            reset();
            display();
            break;
        case 'q':
            playing = false;
            break;
        case 'h':
            showMenu();
            break;
    }
}

const Person* Controller::personNamed(const std::string& name) {
    for (const Person* person : persons) {
        if (name.compare(person->name()) == 0) {
            return person;
        }
    }
    return nullptr;
}

bool Controller::checkConstraints(const Container& container) {
    
    for (const Constraint* constraint : constraints) {
        if (!constraint->check(container)) {
            cout << "### " << constraint->MESSAGE << endl;
            return false;
        }
    }
    return true;
}
