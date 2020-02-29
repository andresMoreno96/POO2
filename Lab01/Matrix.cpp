/* 
 * File:   Matrix.cpp
 * Author: Andres Moreno,Simon Walther
 *
 * Created on February 21, 2020, 3:46 PM
 */
#include "Matrix.hpp"
#include <cstdlib>
#include <ostream>

using namespace std;

Matrix::Matrix() : Matrix(0, 0, 1) {}

Matrix::Matrix(size_t n, size_t m, int mod, bool random) : n(n), m(m), mod(mod), data(nullptr) {

    if (mod <= 0) {
        throw runtime_error("invalid arguments");
    }

    createData();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            data[i][j] = random ? (int) 1 + rand() / (RAND_MAX + 1.0) * mod : 0;
        }
    }
}


Matrix::Matrix(const Matrix &matrix) : n(matrix.n), m(matrix.m), mod(matrix.mod) {

    createData();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            data[i][j] = matrix.data[i][j];
        }
    }
}


Matrix::~Matrix() {

    clearData();
}

void Matrix::checkMod(const Matrix &m1, const Matrix &m2) {
    if (m1.mod != m2.mod) {
        throw invalid_argument("Different modules");
    }
}

Matrix &Matrix::calculate(const Matrix &m2, const Operation &operation) {

    Matrix tmp(*this);

    calculate(tmp, m2, *this, operation);

    return *this;
}

Matrix Matrix::calculateVal(const Matrix &m2, const Operation &operation) const {

    Matrix result;

    calculate(*this, m2, result, operation);

    return result;
}

Matrix *Matrix::calculatePtr(const Matrix &m2, const Operation &operation) const {

    Matrix *result = new Matrix;

    try {
        calculate(*this, m2, *result, operation);

    } catch (invalid_argument &e) {
        delete result;
        throw e;
    }

    return result;
}

void Matrix::calculate(const Matrix &m1, const Matrix &m2, Matrix &result, const Operation &operation) {

    checkMod(m1, m2);

    // Update result matrix data
    result.clearData();
    result.n = max(m1.n, m2.n);
    result.m = max(m1.m, m2.m);
    result.mod = m1.mod;
    result.createData();

    // calculate new values
    for (int i = 0; i < result.n; ++i) {
        for (int j = 0; j < result.n; ++j) {

            int a = (i < m1.n && j < m1.m) ? m1.data[i][j] : 0;
            int b = (i < m2.n && j < m2.m) ? m2.data[i][j] : 0;

            result.data[i][j] = (operation.apply(a, b) % result.mod + result.mod) % result.mod;
        }
    }
}

void Matrix::createData() {

    data = new int *[n];

    for (int i = 0; i < n; ++i) {

        try {
            data[i] = new int[m];

        } catch (bad_alloc &e) {
            // On bad alloc delete what has been allocated
            for (int j = 0; j < i; ++i) {
                delete[] data[j];
            }

            delete data;
            data = nullptr;

            throw e;
        }
    }
}

void Matrix::clearData() {

    if (data == nullptr) return;

    for (int i = 0; i < n; ++i) {
        delete[] data[i];
    }
    delete[] data;
}


Matrix &Matrix::add(const Matrix &m2) {
    return calculate(m2, Addition());
}

Matrix &Matrix::sub(const Matrix &m2) {
    return calculate(m2, Subtraction());
}

Matrix &Matrix::multiply(const Matrix &m2) {
    return calculate(m2, Multiplication());
}

Matrix Matrix::addVal(const Matrix &m2) const {
    return calculateVal(m2, Addition());
}

Matrix Matrix::subVal(const Matrix &m2) const {
    return calculateVal(m2, Subtraction());
}

Matrix Matrix::multiplyVal(const Matrix &m2) const {
    return calculateVal(m2, Multiplication());;
}

Matrix *Matrix::addPtr(const Matrix &m2) const {
    return calculatePtr(m2, Addition());
}

Matrix *Matrix::subPtr(const Matrix &m2) const {
    return calculatePtr(m2, Subtraction());
}

Matrix *Matrix::multiplyPtr(const Matrix &m2) const {
    return calculatePtr(m2, Multiplication());;
}


ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (int i = 0; i < matrix.n; ++i) {
        for (int j = 0; j < matrix.m; ++j) {

            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }

    return os;
}

Matrix &Matrix::operator=(const Matrix &matrix) {

    clearData();
    this->n = matrix.n;
    this->m = matrix.m;
    createData();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            data[i][j] = matrix.data[i][j];
        }
    }

    return *this;
}
