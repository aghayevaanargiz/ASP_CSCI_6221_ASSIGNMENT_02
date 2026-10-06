#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main () {
    int number_of_rows_matrix_A;
    int number_of_columns_matrix_A;
    
    // The user defined matrix sizes
    
    cout << "Enter number of rows for matrix A: ";
    cin >> number_of_rows_matrix_A;
    
    cout << "Enter number of columns for matrix A: ";
    cin >> number_of_columns_matrix_A;
    
    // Using vectors as it is not prefixed in size
    
    vector<vector<int>> matrix_A(
        number_of_rows_matrix_A,
        vector<int>(number_of_columns_matrix_A)
    );
  
    for (int i = 0; i< number_of_rows_matrix_A; i++){
        for (int j = 0; j < number_of_columns_matrix_A; j++) {
            cout << "Enter element [" << i << "][" << j << "] of matrix A: "; // we dont get the values as a raw this time 
            cin >> matrix_A[i][j];
        }
    }
