/*
 * File:   Controller.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on April 13, 2020
 */

#include <iostream>
#include <string>

#include "Controller.hpp"
#include "Person.hpp"
#include "Container.hpp"
#include "Constraint.hpp"

using namespace std;

Controller::Controller(const std::vector<const Person *> persons,
                       const std::vector<const Constraint *> constraints)
        : persons(persons), constraints(constraints), leftBank("Gauche"),
          rightBank("Droite"), boat("Bateau", BOAT_CAPACITY, &leftBank) {

    reset();
}

void Controller::showMenu() const {
    cout << PRINT << "      : afficher" << endl;
    cout << BOARD << " <nom>: embarquer <nom>" << endl;
    cout << UNBOARD << " <nom>: debarquer <nom>" << endl;
    cout << MOVE_BOAT << "      : deplacer bateau" << endl;
    cout << RESTART << "      : reinitialiser" << endl;
    cout << QUIT << "      : quitter" << endl;
    cout << MENU << "      : menu" << endl;
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

    for (const Person *person : persons) {
        leftBank.addPerson(person);
    }
}

void Controller::nextTurn() {
    ++turn;
}


void Controller::move(const Person *person, bool board) {

    nextTurn();
    Bank &bank = boat.bank() == &leftBank ? leftBank : rightBank;

    if (board) {
        if (boat.hasSpace() && bank.contains(person)
            && movePerson(person, bank, boat)) {

            display();
        }
    } else { //unboard

        if (boat.contains(person) && movePerson(person, boat, bank)) {

            display();
        }
    }

}

void Controller::board(const Person *person) {

    move(person, true);

}

void Controller::unboard(const Person *person) {

    move(person, false);

}

void Controller::moveBoat() {

    nextTurn();

    if (boat.canChangeBank()) {
        Bank *bank = boat.bank() == &leftBank ? &rightBank : &leftBank;
        boat.changeBank(bank);

        display();
    }
}

bool Controller::movePerson(const Person *person,
                            Container &from, Container &to) {


    if (checkConstraints(from,person) && checkConstraints(to,person)) {
        from.removePerson(person);
        to.addPerson(person);
        return true;
    }

    return false;

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

void Controller::processCommand(char command, const std::string &argument) {

    const Person *person = personNamed(argument);

    if (command == PRINT) {
        display();
    } else if (command == BOARD) {
        if (person != nullptr) {
            board(person);
        } else {
            std::cout << "### Unknown person." << std::endl;
        }
    } else if (command == UNBOARD) {
        if (person != nullptr) {
            unboard(person);
        } else {
            std::cout << "### Unknown person." << std::endl;
        }
    } else if (command == MOVE_BOAT) {
        moveBoat();
    } else if (command == RESTART) {
        reset();
        display();
    } else if (command == QUIT) {
        playing = false;
    } else if (command == MENU) {
        showMenu();
    }

}

const Person *Controller::personNamed(const std::string &name) {
    for (const Person *person : persons) {
        if (name.compare(person->name()) == 0) {
            return person;
        }
    }
    return nullptr;
}

bool Controller::checkConstraints(const Container &container, const Person* person) {

    for (const Constraint *constraint : constraints) {
        if (!constraint->check(container,person)) {
            cout << "### " << constraint->MESSAGE << endl;
            return false;
        }
    }
    return true;
}


const size_t Controller::getBoatCapacity() {
    return BOAT_CAPACITY;
}
