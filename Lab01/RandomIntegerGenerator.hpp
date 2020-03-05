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
     * @brief generates a random number between 0 and n
     * @param the upper number
     * @return a random number between 0 and n
     */
    static int generateRandomNumber(int n);

    /**
     * @brief initializes the srand() with time(null).
     */
    static void seed();

private:
    static bool seeded; // if rand() has already been seeded

};


#endif //RANDOM_INTEGER_GENERATOR_HPP
