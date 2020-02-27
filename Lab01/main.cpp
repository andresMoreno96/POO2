/* 
 * File:   main.cpp
 * Author: Andres Moreno, Nohan Budry
 *
 * Created on February 21, 2019, 1:33 PM
 */

#include <cstdlib>
#include <iostream>
#include "Matrix.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"

using namespace std;

int main(int argc, char** argv) {

    const int MOD = 5;
    Matrix* ptr;

    cout << "The modulus is : " << MOD << endl << endl;

    try {
        Matrix m1(3, 2, MOD);
        cout << "M1" << endl << m1 << endl;

        Matrix m2(4, 3, MOD);
        cout << "M2" << endl << m2 << endl;

        Matrix tmp1(m1);
        Matrix tmp2(m1);
        Matrix tmp3(m1);

        cout << "By value" << endl;
        cout << "M1 + M2" << endl << m1.calculateVal(m2, Addition()) << endl;
        cout << "M1 - M2" << endl << m1.calculateVal(m2, Subtraction()) << endl;
        cout << "M1 * M2" << endl << m1.calculateVal(m2, Multiplication()) << endl;


        cout << "By modifying the matrix that invokes the method" << endl;
        tmp1.calculate(m2, Addition());
        cout << "M1 + M2" << endl << tmp1 << endl;
        tmp2.calculate(m2, Subtraction());
        cout << "M1 - M2" << endl << tmp2 << endl;
        tmp3.calculate(m2, Multiplication());
        cout << "M1 * M2" << endl << tmp3 << endl;


        cout << "By pointer" << endl;
        ptr = m1.calculatePtr(m2, Addition());
        cout << "M1 + M2" << endl << *ptr << endl;
        delete ptr;
        ptr = m1.calculatePtr(m2, Subtraction());
        cout << "M1 - M2" << endl << *ptr << endl;
        delete ptr;
        ptr = m1.calculatePtr(m2, Multiplication());
        cout << "M1 * M2" << endl << *ptr << endl;
        delete ptr;

    } catch (exception& e) {
        cout << e.what() << endl;
    }

    cout << "----------number of lines or columns negative-------" << endl;

    try {

        Matrix m3(-3, 2, MOD);
        cout << "M3" << endl << m3 << endl;
    } catch (exception& e) {
        cout << e.what() << endl;

    }
    try {
        Matrix m4(4, -3, MOD);
        cout << "M4" << endl << m4 << endl;

    } catch (exception& e) {
        cout << e.what() << endl;
        cout<<endl;

    }


    cout << "-------------------different modulo-------------------" << endl;

    try {

        Matrix m5(3, 2, 2);
        cout << "M5" << endl << m5 << endl;

        Matrix m6(4, 3, 3);
        cout << "M6" << endl << m6 << endl;

        cout << "By value" << endl;
        cout << "M1 + M2" << endl << m5.calculateVal(m6, Addition()) << endl;


    } catch (exception& e) {
        cout << e.what() << endl;
        

    }


    try {

        cout << endl << "--------------- Matrices vides -------------------" << endl;
        
        Matrix m7(0, 0, MOD);
        cout << "M7" << endl << m7 << endl;

        Matrix m8(0, 0, MOD);
        cout << "M8" << endl << m8 << endl;
        
        cout << "M7 + M8" << endl << m7.calculateVal(m8, Addition()) << endl;
        cout << "M7 - M8" << endl << m7.calculateVal(m8, Subtraction()) << endl;
        cout << "M7 * M8" << endl << m7.calculateVal(m8, Multiplication()) << endl;

    } catch (exception& e) {
        cout << e.what() << endl;

    }

    return 0;
}
