/*
 * File:   RandomIntegerGenerator.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on March 3, 2020, 7:21 PM
 */

#ifndef RANDOM_INTEGER_GENERATOR_HPP
#define RANDOM_INTEGER_GENERATOR_HPP

class RandomIntegerGenerator {
public:
    /**
     * @brief Random integer generator constructor
     *
     * @param min the minimum integer generated
     * @param max the maximum integer generated
     *
     * @throws invalid_argument If min is superior or equals to max
     */
    RandomIntegerGenerator(int min, int max);

    /**
     * @brief generate a new random integer
     *
     * @return the random integer generated
     */
    int generate() const;
private:
    static bool seeded; // if rand() as already been seeded
    int min; // min integer generated
    int max; // max integer generated
};


#endif //RANDOM_INTEGER_GENERATOR_HPP
