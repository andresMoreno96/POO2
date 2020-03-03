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

RandomIntegerGenerator::RandomIntegerGenerator(int min, int max) {
    if(!seeded) {
        // seed rand()
        srand(time(nullptr));
        seeded = true;
    }

    if(min < 0 || max < 0) {
        throw std::invalid_argument("Random integer generator's bounds must be positives.");
    }

    if(min >= max) {
        throw std::invalid_argument("Random integer generator's lower bound must be inferior to its upper bound.");
    }

    this->min = min;
    this->max = max;
}

size_t RandomIntegerGenerator::generate() const {
    return min + rand() / (RAND_MAX + 1.0) * (max + 1);
}
