#include <iostream>
#include <vector>

using namespace std;

int main () {
    int number_of_rows_matrix_A;
    int number_of_rows_matrix_B;
    int number_of_columns_matrix_A;
    int number_of_columns_matrix_B;
    
    // The user defined matrix sizes
    
    cout << "Enter number of rows for matrix A: ";
    cin >> number_of_rows_matrix_A;
    
    cout << "Enter number of columns for matrix A: ";
    cin >> number_of_rows_matrix_A;
    
    cout << "Enter number of rows for matrix B: ";
    cin >> number_of_rows_matrix_A;
    
    cout << "Enter number of columns for matrix B: ";
    cin >> number_of_rows_matrix_A;
    
    if (number_of_columns_matrix_A != number_of_rows_matrix_B) {
      cout<< "The multiplication cannot be calculated! Check the matrix size." << endl;
      return 0;
    }

    // Using vectors as it is not prefixed in size
    
    vector<vector<int>> matrix_A(
        number_of_rows_matrix_A,
        vector<int>(number_of_columns_matrix_A)
    );
    vector<vector<int>> matrix_B(
        number_of_rows_matrix_B,
        vector<int>(number_of_columns_matrix_B)
    );

    for (int i = 0; i< number_of_rows_matrix_A; i++){
        for (int j = 0; j < number_of_columns_matrix_A; j++) {
            cout << "Enter a row of matrix A separated by comma: ";
            cin >> matrix_A[i][j];;
        }
    }
    
}
