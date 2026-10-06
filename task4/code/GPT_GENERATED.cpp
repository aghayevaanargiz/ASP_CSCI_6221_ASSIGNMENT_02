#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix
{
private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;

public:
    Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows),
          cols_(cols),
          data_(rows * cols)
    {
    }

    double& at(std::size_t row, std::size_t col)
    {
        return data_[row * cols_ + col];
    }

    const double& at(std::size_t row, std::size_t col) const
    {
        return data_[row * cols_ + col];
    }

    std::size_t rows() const
    {
        return rows_;
    }

    std::size_t cols() const
    {
        return cols_;
    }
};


class MatrixView
{
private:
    const Matrix& matrix_;

    std::size_t row_start_;
    std::size_t row_end_;
    std::size_t col_start_;
    std::size_t col_end_;

public:
    MatrixView(
        const Matrix& matrix,
        std::size_t row_start,
        std::size_t row_end,
        std::size_t col_start,
        std::size_t col_end)
        : matrix_(matrix),
          row_start_(row_start),
          row_end_(row_end),
          col_start_(col_start),
          col_end_(col_end)
    {
        if (row_start > row_end || row_end > matrix.rows())
        {
            throw std::invalid_argument("Invalid row range.");
        }

        if (col_start > col_end || col_end > matrix.cols())
        {
            throw std::invalid_argument("Invalid column range.");
        }

        if (row_start == row_end || col_start == col_end)
        {
            throw std::invalid_argument(
                "Slice must contain at least one row and one column."
            );
        }
    }

    std::size_t rows() const
    {
        return row_end_ - row_start_;
    }

    std::size_t cols() const
    {
        return col_end_ - col_start_;
    }

    double at(std::size_t row, std::size_t col) const
    {
        if (row >= rows() || col >= cols())
        {
            throw std::out_of_range("Slice index out of range.");
        }

        return matrix_.at(
            row_start_ + row,
            col_start_ + col
        );
    }

    void print() const
    {
        for (std::size_t i = 0; i < rows(); ++i)
        {
            for (std::size_t j = 0; j < cols(); ++j)
            {
                std::cout << at(i, j) << ' ';
            }

            std::cout << '\n';
        }
    }
};


Matrix readMatrix(std::size_t rows, std::size_t cols)
{
    Matrix matrix(rows, cols);

    std::cout << "\nEnter the matrix:\n";

    for (std::size_t i = 0; i < rows; ++i)
    {
        std::cout << "Row " << i + 1 << ": ";

        for (std::size_t j = 0; j < cols; ++j)
        {
            while (!(std::cin >> matrix.at(i, j)))
            {
                std::cout << "Invalid input. Please enter a number: ";

                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }

    return matrix;
}


void printMatrix(const Matrix& matrix)
{
    for (std::size_t i = 0; i < matrix.rows(); ++i)
    {
        for (std::size_t j = 0; j < matrix.cols(); ++j)
        {
            std::cout << matrix.at(i, j) << ' ';
        }

        std::cout << '\n';
    }
}


bool readDimension(const char* prompt, std::size_t& value)
{
    std::cout << prompt;

    if (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Invalid input.\n";
        return false;
    }

    if (value == 0)
    {
        std::cout << "Value must be greater than zero.\n";
        return false;
    }

    return true;
}


int main()
{
    std::size_t rows;
    std::size_t cols;

    std::cout << "2D Matrix Slicing using C++\n";
    std::cout << "===========================\n";

    while (!readDimension("Number of rows: ", rows))
    {
    }

    while (!readDimension("Number of columns: ", cols))
    {
    }

    Matrix matrix = readMatrix(rows, cols);

    std::cout << "\nOriginal matrix:\n";
    printMatrix(matrix);

    std::size_t row_start;
    std::size_t row_end;
    std::size_t col_start;
    std::size_t col_end;

    while (true)
    {
        std::cout << "\nEnter slice bounds.\n";
        std::cout << "The end indices are exclusive.\n";

        std::cout << "row_start: ";
        std::cin >> row_start;

        std::cout << "row_end: ";
        std::cin >> row_end;

        std::cout << "col_start: ";
        std::cin >> col_start;

        std::cout << "col_end: ";
        std::cin >> col_end;

        if (std::cin.fail())
        {
            std::cout << "Please enter integer values.\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            continue;
        }

        if (row_start > row_end || row_end > rows)
        {
            std::cout << "Invalid row range.\n";
            continue;
        }

        if (col_start > col_end || col_end > cols)
        {
            std::cout << "Invalid column range.\n";
            continue;
        }

        if (row_start == row_end || col_start == col_end)
        {
            std::cout << "Slice cannot have zero rows or columns.\n";
            continue;
        }

        break;
    }

    /*
     * MatrixView stores only the slicing information.
     * It does not copy any matrix elements.
     */
    MatrixView sliced_matrix(
        matrix,
        row_start,
        row_end,
        col_start,
        col_end
    );

    std::cout << "\nSliced matrix:\n";
    sliced_matrix.print();

    std::cout << "\nSlice dimensions: "
              << sliced_matrix.rows()
              << " x "
              << sliced_matrix.cols()
              << '\n';

    return 0;
}
