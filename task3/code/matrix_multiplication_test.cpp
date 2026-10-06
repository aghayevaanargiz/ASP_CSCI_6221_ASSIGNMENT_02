#include <iostream>
#include <vector>

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

    // Test 1: 2x2 matrix multiplication
    vector<vector<int>> A1 = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B1 = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> expected1 = {
        {19, 22},
        {43, 50}
    };

    vector<vector<int>> result1 = multiplyMatrices(A1, B1);

    if (result1 == expected1) {
        cout << "Test 1 passed!" << endl;
    } else {
        cout << "Test 1 failed!" << endl;
    }


    // Test 2: 2x2 multiplied by 2x3 matrix
    vector<vector<int>> A2 = {
        {2, 3},
        {4, 5}
    };

    vector<vector<int>> B2 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> expected2 = {
        {14, 19, 24},
        {24, 33, 42}
    };

    vector<vector<int>> result2 = multiplyMatrices(A2, B2);

    if (result2 == expected2) {
        cout << "Test 2 passed!" << endl;
    } else {
        cout << "Test 2 failed!" << endl;
    }

    return 0;
}
