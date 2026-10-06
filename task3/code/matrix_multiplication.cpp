#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>>& matrix_A,
    const vector<vector<int>>& matrix_B
) {
    int rows_A = matrix_A.size();
    int columns_A = matrix_A[0].size();
    int columns_B = matrix_B[0].size();

    vector<vector<int>> result(
        rows_A,
        vector<int>(columns_B, 0)
    );

    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < columns_B; j++) {
            for (int k = 0; k < columns_A; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    return result;
}

int main() {
    int number_of_rows_matrix_A;
    int number_of_rows_matrix_B;
    int number_of_columns_matrix_A;
    int number_of_columns_matrix_B;

    // The user defined matrix sizes

    cout << "Enter number of rows for matrix A: ";
    cin >> number_of_rows_matrix_A;

    cout << "Enter number of columns for matrix A: ";
    cin >> number_of_columns_matrix_A;

    cout << "Enter number of rows for matrix B: ";
    cin >> number_of_rows_matrix_B;

    cout << "Enter number of columns for matrix B: ";
    cin >> number_of_columns_matrix_B;

    if (number_of_columns_matrix_A != number_of_rows_matrix_B) {
        cout << "The multiplication cannot be calculated! Check the matrix size." << endl;
        return 0;
    }

    // Using vectors as the matrix size is not fixed

    vector<vector<int>> matrix_A(
        number_of_rows_matrix_A,
        vector<int>(number_of_columns_matrix_A)
    );

    vector<vector<int>> matrix_B(
        number_of_rows_matrix_B,
        vector<int>(number_of_columns_matrix_B)
    );

    for (int i = 0; i < number_of_rows_matrix_A; i++) {
        for (int j = 0; j < number_of_columns_matrix_A; j++) {
            cout << "Enter element [" << i << "][" << j << "] of matrix A: ";
            cin >> matrix_A[i][j];
        }
    }

    for (int i = 0; i < number_of_rows_matrix_B; i++) {
        for (int j = 0; j < number_of_columns_matrix_B; j++) {
            cout << "Enter element [" << i << "][" << j << "] of matrix B: ";
            cin >> matrix_B[i][j];
        }
    }

    auto start = chrono::high_resolution_clock::now();

    vector<vector<int>> multiplication =
        multiplyMatrices(matrix_A, matrix_B);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> execution_time = end - start;

    cout << "Execution time: "
         << execution_time.count()
         << " seconds" << endl;

    cout << "Result of matrix multiplication:" << endl;

    for (int i = 0; i < number_of_rows_matrix_A; i++) {
        for (int j = 0; j < number_of_columns_matrix_B; j++) {
            cout << multiplication[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
