#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyMatrices(
    vector<vector<int>> matrix_A,
    vector<vector<int>> matrix_B
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

    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> expected = {
        {19, 22},
        {43, 50}
    };

    vector<vector<int>> result = multiplyMatrices(A, B);

    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }

    return 0;
}
