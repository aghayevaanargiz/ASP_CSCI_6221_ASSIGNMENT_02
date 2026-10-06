import numpy as np

# Let's get the size of the matrices from user.

number_of_rows_matrix_A = int(input("Enter number of rows for matrix A: "))
number_of_rows_matrix_B = int(input("Enter number of rows for matrix B: "))
number_of_columns_matrix_A = int(input("Enter number of columns for matrix A: "))
number_of_columns_matrix_B = int(input("Enter number of columns for matrix B: "))

# Here i should check whether the matrices sizes matches. To multiply 2 matrices the num of columns of matrix A must be equal to num of rows of matrix B. 

if number_of_columns_matrix_A != number_of_rows_matrix_B:
    print("The multiplication cannot be calculated! Check the matrix size.")

