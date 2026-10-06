import numpy as np
import time


def read_matrix(rows, cols, name):
    print(f"Enter the elements of matrix {name}:")

    elements = []

    for i in range(rows):
        while True:
            row = input(f"Row {i + 1}: ").split()

            if len(row) != cols:
                print(f"Please enter exactly {cols} values.")
                continue

            try:
                elements.append([float(value) for value in row])
                break
            except ValueError:
                print("Please enter numeric values.")

    return np.array(elements)


def main():
    print("Matrix Multiplication using NumPy")
    print("----------------------------------")

    while True:
        try:
            rows_a = int(input("Number of rows in matrix A: "))
            cols_a = int(input("Number of columns in matrix A: "))
            rows_b = int(input("Number of rows in matrix B: "))
            cols_b = int(input("Number of columns in matrix B: "))

            if min(rows_a, cols_a, rows_b, cols_b) <= 0:
                print("Matrix dimensions must be positive.")
                continue

            break

        except ValueError:
            print("Please enter integer dimensions.")

    if cols_a != rows_b:
        print(
            "Matrix multiplication is not possible: "
            "the number of columns of A must equal the number of rows of B."
        )
        return

    matrix_a = read_matrix(rows_a, cols_a, "A")
    matrix_b = read_matrix(rows_b, cols_b, "B")

    start_time = time.perf_counter()

    result = np.matmul(matrix_a, matrix_b)

    end_time = time.perf_counter()

    execution_time = end_time - start_time

    print("\nMatrix A:")
    print(matrix_a)

    print("\nMatrix B:")
    print(matrix_b)

    print("\nResult:")
    print(result)

    print(f"\nExecution time: {execution_time:.9f} seconds")


if __name__ == "__main__":
    main()
