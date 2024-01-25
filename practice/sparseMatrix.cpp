#include <iostream>
#define MAXTERMS 10
using namespace std;
class sparseMatrix; // forward declaration
class matrixTerm
{
    friend class sparseMatrix;

private:
    int col, row, value;
};
class sparseMatrix
{
public:
    sparseMatrix transpose();

private:
    int cols, rows, terms;
    matrixTerm smArr[MAXTERMS];
};

sparseMatrix sparseMatrix::transpose()
{
    sparseMatrix buffer;
    buffer.rows = cols;
    buffer.cols = rows;
    buffer.terms = terms;
    if (terms > 0) // nonzero matrix
    {
        int currentBuffer = 0;
        for (int c = 0; c < cols; c++) // transpose by column
        {
            for (int i = 0; i < terms; i++)
            {
                if (smArr[i].col == c)
                {
                    buffer.smArr[currentBuffer].row = c;
                    buffer.smArr[currentBuffer].col = smArr[i].row;
                    buffer.smArr[currentBuffer].value = smArr[i].value;
                    currentBuffer++;
                }
            }
        }
    }
    return buffer;
}

/*time complexity: O(term x columns) = O(rows x columns x columns)*/