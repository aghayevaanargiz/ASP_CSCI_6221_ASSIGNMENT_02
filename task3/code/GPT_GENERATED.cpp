#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

using Matrix = std::vector<std::vector<double>>;


Matrix multiply(const Matrix& a, const Matrix& b)
{
    if (a.empty() || b.empty())
    {
        throw std::invalid_argument("Matrices cannot be empty.");
    }

    const std::size_t rowsA = a.size();
    const std::size_t colsA = a[0].size();
    const std::size_t rowsB = b.size();
    const std::size_t colsB = b[0].size();

    if (colsA != rowsB)
    {
        throw std::invalid_argument(
            "Matrix dimensions are incompatible."
        );
    }

    Matrix result(rowsA, std::vector<double>(colsB, 0.0));

    for (std::size_t i = 0; i < rowsA; ++i)
    {
        for (std::size_t k = 0; k < colsA; ++k)
        {
            for (std::size_t j = 0; j < colsB; ++j)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}


bool matricesEqual(
    const Matrix& a,
    const Matrix& b,
    double tolerance = 1e-9)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (std::size_t i = 0; i < a.size(); ++i)
    {
        if (a[i].size() != b[i].size())
        {
            return false;
        }

        for (std::size_t j = 0; j < a[i].size(); ++j)
        {
            if (std::abs(a[i][j] - b[i][j]) > tolerance)
            {
                return false;
            }
        }
    }

    return true;
}


void testTwoByTwoMultiplication()
{
    Matrix a = {
        {1, 2},
        {3, 4}
    };

    Matrix b = {
        {5, 6},
        {7, 8}
    };

    Matrix expected = {
        {19, 22},
        {43, 50}
    };

    assert(matricesEqual(multiply(a, b), expected));
}


void testRectangularMatrices()
{
    Matrix a = {
        {1, 2, 3},
        {4, 5, 6}
    };

    Matrix b = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    Matrix expected = {
        {58, 64},
        {139, 154}
    };

    assert(matricesEqual(multiply(a, b), expected));
}


void testIdentityMatrix()
{
    Matrix a = {
        {2, 3},
        {4, 5}
    };

    Matrix identity = {
        {1, 0},
        {0, 1}
    };

    assert(matricesEqual(multiply(a, identity), a));
}


void testIncompatibleDimensions()
{
    Matrix a = {
        {1, 2, 3}
    };

    Matrix b = {
        {1, 2},
        {3, 4}
    };

    bool exceptionThrown = false;

    try
    {
        multiply(a, b);
    }
    catch (const std::invalid_argument&)
    {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}


int main()
{
    testTwoByTwoMultiplication();
    testRectangularMatrices();
    testIdentityMatrix();
    testIncompatibleDimensions();

    std::cout << "All tests passed successfully.\n";

    return 0;
}
