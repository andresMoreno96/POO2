/* 
 * File:   main.cpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on February 21, 2020, 1:33 PM
 */

#include <cstdlib>
#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main() {

    const int MOD = 5;
    Matrix *ptr;

    cout << "The mod is : " << MOD << endl << endl;

    try {
        Matrix m1(3, 2, MOD);
        cout << "M1" << endl << m1 << endl;

        Matrix m2(4, 3, MOD);
        cout << "M2" << endl << m2 << endl;

        Matrix tmp1(m1);
        Matrix tmp2(m1);
        Matrix tmp3(m1);

        cout << "By value" << endl;
        cout << "M1 + M2" << endl << m1.addVal(m2) << endl;
        cout << "M1 - M2" << endl << m1.subVal(m2) << endl;
        cout << "M1 * M2" << endl << m1.multiplyVal(m2) << endl;

        cout << "By modifying the matrix that invokes the method" << endl;
        tmp1.add(m2);
        cout << "M1 + M2" << endl << tmp1 << endl;
        tmp2.sub(m2);
        cout << "M1 - M2" << endl << tmp2 << endl;
        tmp3.multiply(m2);
        cout << "M1 * M2" << endl << tmp3 << endl;


        cout << "By pointer" << endl;
        ptr = m1.addPtr(m2);
        cout << "M1 + M2" << endl << *ptr << endl;
        delete ptr;
        ptr = m1.subPtr(m2);
        cout << "M1 - M2" << endl << *ptr << endl;
        delete ptr;
        ptr = m1.multiplyPtr(m2);
        cout << "M1 * M2" << endl << *ptr << endl;
        delete ptr;

    } catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << "-------------------different modulo-------------------" << endl;

    try {
        Matrix m5(3, 2, 2);
        cout << "M5" << endl << m5 << endl;

        Matrix m6(4, 3, 3);
        cout << "M6" << endl << m6 << endl;

        cout << "By value" << endl;
        cout << "M1 + M2" << endl << m5.addVal(m6) << endl;


    } catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << "-------------------Constant matrix-------------------" << endl;
    
    const Matrix cm1(3,4,MOD);
    cout << "M1" << endl << cm1 << endl;

    const Matrix cm2(3,4,MOD);
    cout << "M2" << endl << cm2 << endl;

    Matrix tmp1(cm1);
    Matrix tmp2(cm1);
    Matrix tmp3(cm1);

    cout << "By value" << endl;
    cout << "M1 + M2" << endl << cm1.addVal(cm2) << endl;
    cout << "M1 - M2" << endl << cm1.subVal(cm2) << endl;
    cout << "M1 * M2" << endl << cm1.multiplyVal(cm2) << endl;

    cout << "By modifying the matrix that invokes the method" << endl;
    tmp1.add(cm2);
    cout << "M1 + M2" << endl << tmp1 << endl;
    tmp2.sub(cm2);
    cout << "M1 - M2" << endl << tmp2 << endl;
    tmp3.multiply(cm2);
    cout << "M1 * M2" << endl << tmp3 << endl;

    cout << "By pointer" << endl;
    ptr = cm1.addPtr(cm2);
    cout << "M1 + M2" << endl << *ptr << endl;
    delete ptr;
    ptr = cm1.subPtr(cm2);
    cout << "M1 - M2" << endl << *ptr << endl;
    delete ptr;
    ptr = cm1.multiplyPtr(cm2);
    cout << "M1 * M2" << endl << *ptr << endl;
    delete ptr;

    try {
        Matrix cm5(3, 2, 2);
        cout << "M5" << endl << cm5 << endl;

        Matrix cm6(4, 3, 3);
        cout << "M6" << endl << cm6 << endl;

        cout << "By value" << endl;
        cout << "M1 + M2" << endl << cm5.addVal(cm6) << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return EXIT_SUCCESS;
}
