import numpy as np

# Let's get the size of the matrices from user.

number_of_rows_matrix_A = int(input("Enter number of rows for matrix A: "))
number_of_rows_matrix_B = int(input("Enter number of rows for matrix B: "))
number_of_columns_matrix_A = int(input("Enter number of columns for matrix A: "))
number_of_columns_matrix_B = int(input("Enter number of columns for matrix B: "))

# Here i should check whether the matrices sizes matches. To multiply 2 matrices the num of columns of matrix A must be equal to num of rows of matrix B. 

if number_of_columns_matrix_A != number_of_rows_matrix_B:
    print("The multiplication cannot be calculated! Check the matrix size.")

# Now time to get the matrix values from user, I want to create a list and add the rows there as a sublist (might be stupid idea let's see)

rows_of_matrix_A = []
rows_of_matrix_B = []
columns_of_matrix_A = []
columns_of_matrix_B = []

# Okay first let's get the row's of matrix A

for i in range(number_of_rows_matrix_A):
    row_input = input("Enter a row of matrix A separated by comma: ")
    row = row_input.split(",")

    for j in range(len(row)):
        row[j] = int(row[j])

    rows_of_matrix_A.append(row)


# Not let's get the rows of matrix B the same loop implementation just for matrix B

for i in range(number_of_rows_matrix_B):
    row_input = input("Enter a row of matrix B separated by comma: ")
    row = row_input.split(",")

    for j in range(len(row)):
        row[j] = int(row[j])

    rows_of_matrix_B.append(row)


# Now let's create columns

for i in range(number_of_rows_matrix_A):
    column_input = input("Enter a column of matrix A separated by comma: ")
    columnt = column_input.split(",")

    for j in range(len(column)):
        column[j] = int(column[j])

    rows_of_matrix_A.append(column)



