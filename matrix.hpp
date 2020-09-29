#ifndef QUADRIC_MATRIX_MODULE_HPP
#define QUADRIC_MATRIX_MODULE_HPP

#include <cmath>
#include <cstdlib>



/*
 * Incapsulates square matrix.
 */
class Matrix
{
    double **data;      /* data is stored row-major */
    int size;

public:
    Matrix(){ data = 0; }
    Matrix(int size){ create(size); }
    ~Matrix(){ clear(); }

    double &operator()(int i, int j){ return data[i][j]; }
    const double &operator()(int i, int j) const { return data[i][j]; }
    int getSize() const { return size; }

    /*
     * Swaps i-th and j-th row.
     */
    void swapRows(int i, int j)
    {
        double *buf = data[i];
        data[i] = data[j];
        data[j] = buf;
    }

    /*
     * Returns the id of row with the greatest absolute value in n-th
     * column among the last n rows.
     */
    int findMaxAbsElementRow(int n);

private:
    Matrix(const Matrix &A);
    void operator=(const Matrix &A);

    /*
     * Disposes matrix data.
     */
    void clear();

    /*
     * Creates a new data storage of a given size.
     */
    void create(int size);
};



/*
 * Solves the system of the given matrix and right parts,
 * returning solution in the right part array.
 *
 * Note: the matrix is changed after performing this function.
 */
void solveGauss(Matrix &matrix, double f[]);

#endif
