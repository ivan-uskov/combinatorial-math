#include "stdafx.h"
#include "Matrix.h"

using namespace std;

Matrix::Matrix(size_t length, vector<int> const& values)
{
    if (pow(length, 2) != values.size())
    {
        throw invalid_argument("Matrix values has error length!");
    }

    this->length = length;
    this->values = values;
}

size_t Matrix::GetLength()const
{
    return length;
}

Matrix Matrix::GetDegreeMatrix()const
{
    Matrix mtx(length, vector<int>(ElementsCount(), 0));

    for (unsigned y = 0; y < length; ++y)
    {
        unsigned degree = 0;
        for (unsigned x = 0; x < length; ++x)
        {
            degree += (*this)(x, y);
        }
        mtx(y, y) = degree;
    }

    return mtx;
}

Matrix Matrix::GetAdditionMatrix(size_t dx, size_t dy)const
{
    vector<int> additionValues;

    for (size_t y = 0; y < length; ++y)
    {
        for (size_t x = 0; x < length; ++x)
        {
            if (x != dx && y != dy)
            {
                additionValues.push_back((*this)(x, y));
            }
        }
    }

    return Matrix(length - 1, additionValues);
}

size_t Matrix::FindInCol(size_t col, function<bool(int)> const& comp)const
{
    for (size_t y = 0; y < length; ++y)
    {
        if (comp((*this)(col, y)))
        {
            return y;
        }
    }

    throw domain_error("Not Found");
}

size_t Matrix::FindInRow(size_t row, function<bool(int)> const& comp)const
{
    for (size_t x = 0; x < length; ++x)
    {
        if (comp((*this)(x, row)))
        {
            return x;
        }
    }

    return length;
}

Matrix Matrix::GetDiagonalMatrix()const
{

}

size_t Matrix::GetDeterminant()const
{
    auto mtx = GetDiagonalMatrix();

    size_t dtmt = 1;
    for (size_t i = 0; i < length; ++i)
    {
        dtmt *= mtx(i, i);
    }

    return dtmt;
}

size_t Matrix::GetCountSpanningTrees()const
{
    return (GetDegreeMatrix() - *this).GetAdditionMatrix(1, 1).GetDeterminant();
}

size_t Matrix::ElementsCount()const
{
    return static_cast<size_t>(pow(length, 2));
}

void Matrix::SwapRows(size_t lhs, size_t rhs)
{
    for (size_t x = 0; x < length; ++x)
    {
        swap((*this)(x, lhs), (*this)(x, rhs));
    }
}

void Matrix::SwapCols(size_t lhs, size_t rhs)
{
    for (size_t y = 0; y < length; ++y)
    {
        swap((*this)(lhs, y), (*this)(rhs, y));
    }
}

int & Matrix::operator () (size_t x, size_t y)
{
    return values.at(y * length + x);
}

int const& Matrix::operator () (size_t x, size_t y)const
{
    return values.at(y * length + x);
}

Matrix operator - (Matrix const& lhs, Matrix const& rhs)
{
    size_t length = lhs.GetLength();
    if (length != rhs.GetLength())
    {
        throw invalid_argument("Sub Matrixies with different length!");
    }

    Matrix mtx(length, vector<int>(lhs.ElementsCount(), 0));
    for (size_t y = 0; y < length; ++y)
    {
        for (size_t x = 0; x < length; ++x)
        {
            mtx(x, y) = lhs(x, y) - rhs(x, y);
        }
    }

    return mtx;
}

void Matrix::Print(std::ostream & out)const
{
    for (size_t y = 0; y < length; ++y)
    {
        for (size_t x = 0; x < length; ++x)
        {
            out << (*this)(x, y) << " ";
        }
        out << endl;
    }
}