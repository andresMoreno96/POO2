/*
 * File:   RandomIntegerGenerator.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on March 3, 2020, 7:21 PM
 */

#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include "RandomIntegerGenerator.hpp"

bool RandomIntegerGenerator::seeded;


int RandomIntegerGenerator::generateRandomNumber(int n) {

    return (int) rand() / (RAND_MAX + 1.0) * n;
}

void RandomIntegerGenerator::seed() {

    if (!seeded) {
        // seed rand()
        srand(time(NULL));
        seeded = true;
    }


}
