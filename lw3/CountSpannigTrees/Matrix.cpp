#include "stdafx.h"
#include "Matrix.h"

using namespace std;

Matrix::Matrix(size_t length, vector<double> const& values)
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
    Matrix mtx(length, vector<double>(ElementsCount(), 0));

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
    vector<double> additionValues;

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

void Matrix::SwitchToNotZeroRow(size_t x)
{
    if (DblsEqual((*this)(x, x), 0))
    {
        for (size_t y = 0; y < length; ++y)
        {
            if (!DblsEqual((*this)(x, y), 0))
            {
                SwapRows(x, y);
                break;
            }

            if (y + 1 == length)
            {
                throw domain_error("can't create diagonal matrix");
            }
        }
    }
}

std::vector<double> Matrix::GetRowDeletedOnFirstElement(size_t x)const
{
    auto row = GetRow(x);
    for (size_t i = 0; i < length; ++i)
    {
        row[i] /= (*this)(x, x);
    }

    return row;
}

void Matrix::MakeColumnZero(std::vector<double> const& row, size_t x)
{
    for (size_t y = 0; y < length; ++y)
    {
        if (y != x)
        {
            for (size_t i = x; i < length; ++i)
            {
                (*this)(y, i) -= row[i] * (*this)(x, y);
            }
        }
    }
}

Matrix Matrix::GetDiagonalMatrix()const
{
    Matrix mtx(*this);

    for (size_t x = 0; x < length; ++x)
    {
        mtx.SwitchToNotZeroRow(x);
        auto row = mtx.GetRowDeletedOnFirstElement(x);
        mtx.MakeColumnZero(row, x);
    }

    return mtx;
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

std::vector<double> Matrix::GetRow(size_t y)const
{
    auto beg = values.begin() + y * length;
    auto end = beg + length;

    return vector<double>(beg, end);
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

double & Matrix::operator () (size_t x, size_t y)
{
    return values.at(y * length + x);
}

double const& Matrix::operator () (size_t x, size_t y)const
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

    Matrix mtx(length, vector<double>(lhs.ElementsCount(), 0));
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