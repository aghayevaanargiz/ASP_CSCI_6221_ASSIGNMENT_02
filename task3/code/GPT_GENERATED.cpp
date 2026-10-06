#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<double>>;


Matrix readMatrix(std::size_t rows, std::size_t cols, const std::string& name)
{
    Matrix matrix(rows, std::vector<double>(cols));

    std::cout << "\nEnter matrix " << name
              << " (" << rows << " x " << cols << "):\n";

    for (std::size_t i = 0; i < rows; ++i)
    {
        std::cout << "Row " << i + 1 << ": ";

        for (std::size_t j = 0; j < cols; ++j)
        {
            while (!(std::cin >> matrix[i][j]))
            {
                std::cout << "Invalid input. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }

    return matrix;
}


Matrix multiply(const Matrix& a, const Matrix& b)
{
    if (a.empty() || b.empty())
    {
        throw std::invalid_argument("Matrices cannot be empty.");
    }

    const std::size_t rows_a = a.size();
    const std::size_t cols_a = a[0].size();
    const std::size_t rows_b = b.size();
    const std::size_t cols_b = b[0].size();

    if (cols_a != rows_b)
    {
        throw std::invalid_argument(
            "Matrix dimensions are incompatible for multiplication."
        );
    }

    Matrix result(rows_a, std::vector<double>(cols_b, 0.0));

    for (std::size_t i = 0; i < rows_a; ++i)
    {
        for (std::size_t k = 0; k < cols_a; ++k)
        {
            for (std::size_t j = 0; j < cols_b; ++j)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}


void printMatrix(const Matrix& matrix)
{
    for (const auto& row : matrix)
    {
        for (double value : row)
        {
            std::cout << std::setw(10)
                      << std::fixed
                      << std::setprecision(2)
                      << value;
        }

        std::cout << '\n';
    }
}


int main()
{
    std::size_t rows_a;
    std::size_t cols_a;
    std::size_t rows_b;
    std::size_t cols_b;

    std::cout << "Matrix Multiplication using C++\n";
    std::cout << "================================\n";

    std::cout << "Number of rows in matrix A: ";
    std::cin >> rows_a;

    std::cout << "Number of columns in matrix A: ";
    std::cin >> cols_a;

    std::cout << "Number of rows in matrix B: ";
    std::cin >> rows_b;

    std::cout << "Number of columns in matrix B: ";
    std::cin >> cols_b;

    if (rows_a == 0 || cols_a == 0 ||
        rows_b == 0 || cols_b == 0)
    {
        std::cerr << "Matrix dimensions must be positive.\n";
        return 1;
    }

    if (cols_a != rows_b)
    {
        std::cerr
            << "\nMatrix multiplication is not possible.\n"
            << "The number of columns in matrix A must equal "
            << "the number of rows in matrix B.\n";

        return 1;
    }

    Matrix matrix_a = readMatrix(rows_a, cols_a, "A");
    Matrix matrix_b = readMatrix(rows_b, cols_b, "B");

    std::cout << "\nMatrix A:\n";
    printMatrix(matrix_a);

    std::cout << "\nMatrix B:\n";
    printMatrix(matrix_b);

    const auto start = std::chrono::high_resolution_clock::now();

    Matrix result = multiply(matrix_a, matrix_b);

    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> elapsed = end - start;

    std::cout << "\nResult of A x B:\n";
    printMatrix(result);

    std::cout << "\nExecution time: "
              << std::fixed
              << std::setprecision(9)
              << elapsed.count()
              << " seconds\n";

    return 0;
}
