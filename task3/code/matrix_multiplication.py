import numpy as np
import time

# Let's get the size of the matrices from user.

number_of_rows_matrix_A = int(input("Enter number of rows for matrix A: "))
number_of_rows_matrix_B = int(input("Enter number of rows for matrix B: "))
number_of_columns_matrix_A = int(input("Enter number of columns for matrix A: "))
number_of_columns_matrix_B = int(input("Enter number of columns for matrix B: "))

# Here i should check whether the matrices sizes matches. To multiply 2 matrices the num of columns of matrix A must be equal to num of rows of matrix B. 

if number_of_columns_matrix_A != number_of_rows_matrix_B:
    print("The multiplication cannot be calculated! Check the matrix size.")
    exit()

# Now time to get the matrix values from user, I want to create a list and add the rows there as a sublist (might be stupid idea let's see)

rows_of_matrix_A = []
rows_of_matrix_B = []

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


# Not let's get the rows of matrix B the same loop implementation just for matrix B

for i in range(number_of_rows_matrix_B):
    row_input = input("Enter a row of matrix B separated by comma: ")
    row = row_input.split(",")

    for j in range(len(row)):
        row[j] = int(row[j])

    if len(row) != number_of_columns_matrix_B:
        print("The number of elements in the row does not match the matrix dimensions.")
        exit()
        
    rows_of_matrix_B.append(row)

# Now let's convert our lists into numpy arrays

matrix_A = np.array(rows_of_matrix_A)
matrix_B = np.array(rows_of_matrix_B)

# Finally let's multiply the matrices and print the results

start = time.perf_counter()

multiplication = matrix_A @ matrix_B

end = time.perf_counter()

print("Execution time:", end - start, "seconds")

print(multiplication)




