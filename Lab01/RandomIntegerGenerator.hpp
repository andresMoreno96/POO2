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
     */
    RandomIntegerGenerator(int min, int max);

    /**
     * @brief generate a new random integer
     *
     * @return the random integer generated
     */
    size_t generate() const;
private:
    static bool seeded; // if rand() as already been seeded
    size_t min; // min integer generated
    size_t max; // max integer generated
};


#endif //RANDOM_INTEGER_GENERATOR_HPP
