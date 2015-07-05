#pragma once

class Matrix
{
public:
    Matrix(){};
    Matrix(size_t length, std::vector<double> const&);

    Matrix GetDegreeMatrix()const;
    Matrix GetDiagonalMatrix()const;
    Matrix GetAdditionMatrix(size_t, size_t)const;

    size_t GetLength()const;
    size_t ElementsCount()const;
    size_t GetCountSpanningTrees()const;
    size_t GetDeterminant()const;

    double & operator ()(size_t, size_t);
    double const& operator ()(size_t, size_t)const;

    void SwapRows(size_t, size_t);
    void SwapCols(size_t, size_t);

    void Print(std::ostream & out)const;

private:

    void SwitchToNotZeroRow(size_t);
    std::vector<double> GetRow(size_t)const;
    std::vector<double> GetRowDeletedOnFirstElement(size_t)const;
    void MakeColumnZero(std::vector<double> const& row, size_t x);

    std::vector<double> values;
    size_t length;
};

Matrix operator - (Matrix const&, Matrix const&);

std::ostream operator << (std::ostream & out, Matrix const& mtx);