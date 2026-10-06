import numpy as np

number_of_rows_matrix_A = int(input("Enter number of rows for matrix A: "))
number_of_columns_matrix_A = int(input("Enter number of columns for matrix A: "))

rows_of_matrix_A = []


# Okay first let's get the row's of matrix A

for i in range(number_of_rows_matrix_A):
    row_input = input("Enter a row of matrix A separated by comma: ")
    row = row_input.split(",")

    for j in range(len(row)):
        row[j] = int(row[j])

    if len(row) != number_of_columns_matrix_A:
        print("The number of elements in the row does not match the matrix dimensions.")
        exit()
        
    rows_of_matrix_A.append(row)
