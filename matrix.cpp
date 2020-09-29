#include "matrix.hpp"

void Matrix::create(int size)
{
    this->size = size;
    data = new double *[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = new double[size];
    }
}



void Matrix::clear()
{
    if (data)
    {
        for (int i = 0; i < size; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }
}



int Matrix::findMaxAbsElementRow(int n)
{
    double tmp;
    double max = fabs(data[n][n]);
    int res = n;

    for (int i = n + 1; i < size; i++)
    {
        tmp = fabs(data[i][n]);
        if (tmp > max)
        {
            res = i;
            max = tmp;
        }
    }

    return res;
}



/*
 * Makes one gauss forward step (for the n-th string).
 */
void gaussStep(Matrix &A, int n)
{
    double m;
    double w = A(n, n);

    for (int i = n + 1; i < A.getSize(); i++)
    {
        m = A(i, n) / w;

        for (int j = n + 1; j < A.getSize(); j++)
        {
            A(i, j) -= m * A(n, j);
        }

        A(i, n) = 0.0;
    }
}



double getDeterminant(Matrix &matrix)
{
    int maxRow;

    for (int i = 0; i < matrix.getSize() - 1; i++)
    {
        maxRow = matrix.findMaxAbsElementRow(i);

        if (maxRow != i)
        {
            matrix.swapRows(i, maxRow);
        }

        gaussStep(matrix, i);
        if (isZero(matrix(i, i)))
        {
            return 0.0;
        }
    }

    double det = matrix(0, 0);
    for (int i = 1; i < matrix.getSize(); i++)
    {
        det *= matrix(i, i);
    }

    return det;
}
