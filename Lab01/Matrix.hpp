/* 
 * File:   Matrix.hpp
 * Author: Andres Moreno, Simon Walther
 *
 * Created on February 21, 2019, 3:46 PM
 * 
 * Class capable of representing a matrix of a size N x M, where N stands for 
 * the lines and M for the columns. All the elements of the matrix are between 
 * 0 and n-1 for a whole number n. (the whole numbers are modulo n).
 * 
 * 
 */

#ifndef Matrix_h
#define Matrix_h

#include <ostream>
#include "Operation.hpp"
#include "Addition.hpp"
#include "Subtraction.hpp"
#include "Multiplication.hpp"

class Matrix {
    size_t n; //number of lines.
    size_t m; //number of columns.
    int mod; // the modulo of the matrix.
    int **data; // values of the matrix.

public:
    /**
     * @brief empty constructor
     */
    Matrix();

    /**
     * @brief constructor capable to initialize a matrix generating random data
     * by passing the amount of lines, columns and the value of the modulo.
     * 
     * @param n amount of lines that matrix will have.
     * @param m amount of columns that the matrix will have.
     * @param mod the modulo of the matrix,
     * @param random true if the matrix will be generated with random numbers, 
     * false if the matrix will be filled with 0's.
     * 
     * @throws runtime_error if the modulo is negative.
     *
     */
    Matrix(size_t n, size_t m, int mod, bool random = true);

    /**
     * @brief copy constructor.
     * @param matrix the matrix we desire to copy.
     */
    Matrix(const Matrix &matrix);

    /**
     * @brief destructor.
     */
    virtual ~Matrix();

    /**
     * @brief overload of the equal operator
     *
     */
    Matrix &operator=(const Matrix &matrix);


    /**
     * @brief method capable of performing an addition between
     * two matrices modifying the matrix on which the method is invoked.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return the matrix
     * @throw invalid-argument
     */
    Matrix &add(const Matrix &m2);

    /**
     * @brief method capable of performing a subtraction between
     * two matrices modifying the matrix on which the method is invoked.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return the matrix.
     * @throw invalid-argument
     */
    Matrix &sub(const Matrix &m2);

    /**
     * @brief method capable of performing a multiplication between
     * two matrices modifying the matrix on which the method is invoked.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return the matrix
     * @throw invalid-argument
     */
    Matrix &multiply(const Matrix &m2);


    /**
     * @brief method capable of performing an addition between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a new result Matrix statically allocated containing the result of
     * the operation.
     *
     * @throw invalid-argument
     */
    Matrix addVal(const Matrix &m2) const;

    /**
     * @brief method capable of performing a subtraction between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a new result Matrix statically allocated containing the result of
     * the operation.
     *
     * @throw invalid-argument
     */
    Matrix subVal(const Matrix &m2) const;

    /**
     * @brief method capable of performing a multiplication between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a new result Matrix statically allocated containing the result of
     * the operation.
     *
     * @throw invalid-argument
     */
    Matrix multiplyVal(const Matrix &m2) const;

    /**
     * @brief method capable of performing an addition between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a pointer on a new matrix dynamically allocated containing
     * the result of the operation.
     *
     * @throw invalid-argument
     */
    Matrix *addPtr(const Matrix &m2) const;

    /**
     * @brief method capable of performing a subtraction between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a pointer on a new matrix dynamically allocated containing
     * the result of the operation.
     *
     * @throw invalid-argument
     */
    Matrix *subPtr(const Matrix &m2) const;

    /**
     * @brief method capable of performing a multiplication between
     * two matrices.
     *
     * @param m2 matrix that we desire to perform the operation with.
     * @return a pointer on a new matrix dynamically allocated containing
     * the result of the operation.
     *
     * @throw invalid-argument
     */
    Matrix *multiplyPtr(const Matrix &m2) const;

    /**
     * @brief overload of the stream operator '<<'.
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);


private:

    /**
     * @brief method capable of performing different operations between
     * two matrices modifying the matrix on which the method is invoked.
     *
     * @param m2  matrix that we desire to perform the operation with.
     * @param operation operation that we desire to apply (addition,
     * subtraction or multiplication ).
     *
     * @throw invalid-argument
     */
    Matrix &calculate(const Matrix &m2, const Operation &operation);

    /**
     * @brief method capable of performing different operations between
     * two matrices.
     *
     * @param m2  matrix that we desire to perform the operation with.
     * @param operation operation that we desire to apply (addition,
     * subtraction or multiplication ).
     *
     * @return a new result Matrix statically allocated containing the result of
     * the operation.
     *
     * @throw invalid-argument
     */
    Matrix calculateVal(const Matrix &m2, const Operation &operation) const;

    /**
     * @brief method capable of performing different operations between
     * two matrices.
     *
     * @param m2  matrix that we desire to perform the operation with.
     * @param operation operation that we desire to apply (addition,
     * subtraction or multiplication ).
     *
     * @return a pointer on a new matrix dynamically allocated containing
     * the result of the operation.
     *
     * @throw invalid-argument
     */
    Matrix *calculatePtr(const Matrix &m2, const Operation &operation) const;

    /**
     * @brief method that checks if the matrices possess the same modulo
     * @param m1 matrix
     * @param m2 matrix
     * @throws invalid_argument if the modulo of the matrices is not the same.
     */
    static void checkMod(const Matrix &m1, const Matrix &m2);

    /**
     * @brief method capable of performing different operations between 
     * two matrices.
     * 
     * @param m1  matrix that we desire to perform the operation with
     * @param m2  matrix that we desire to perform the operation with.
     * @param result matrix containing the result of the 
     * operation between m1 et m2. 
     * 
     * @param operation operation that we desire to apply (addition,
     * subtraction or multiplication ).
     * 
     */
    static void calculate(const Matrix &m1, const Matrix &m2, Matrix &result, const Operation &operation);


    /**
     * @brief initializes the data of the matrix.
     */
    void createData();

    /**
     * @brief clears the data of the matrix.
     */
    void clearData();
};

#endif /* Matrix_h */
