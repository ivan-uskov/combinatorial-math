#pragma once

class Matrix
{
public:
    Matrix(){};
    Matrix(size_t length, std::vector<int> const&);

    Matrix GetDegreeMatrix()const;
    Matrix GetDiagonalMatrix()const;
    Matrix GetAdditionMatrix(size_t, size_t)const;

    size_t GetLength()const;
    size_t ElementsCount()const;
    size_t GetCountSpanningTrees()const;
    size_t GetDeterminant()const;

    int & operator ()(size_t, size_t);
    int const& operator ()(size_t, size_t)const;

    void SwapRows(size_t, size_t);
    void SwapCols(size_t, size_t);

    void Print(std::ostream & out)const;

    size_t FindInCol(size_t, std::function<bool(int)> const&)const;
    size_t FindInRow(size_t, function<bool(int)> const&)const;

private:
    std::vector<int> values;
    size_t length;
};

Matrix operator - (Matrix const&, Matrix const&);

std::ostream operator << (std::ostream & out, Matrix const& mtx);