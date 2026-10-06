import numpy as np
import time


def read_matrix(rows, cols, name):
    print(f"\nEnter matrix {name} ({rows} x {cols}):")

    matrix = []

    for i in range(rows):
        while True:
            try:
                row = list(map(float, input(f"Row {i + 1}: ").split()))

                if len(row) != cols:
                    print(f"Please enter exactly {cols} values.")
                    continue

                matrix.append(row)
                break

            except ValueError:
                print("Please enter numeric values only.")

    return np.array(matrix)


def main():
    print("Matrix Multiplication using NumPy")
    print("=================================")

    while True:
        try:
            rows_a = int(input("Number of rows in matrix A: "))
            cols_a = int(input("Number of columns in matrix A: "))

            rows_b = int(input("Number of rows in matrix B: "))
            cols_b = int(input("Number of columns in matrix B: "))

            if rows_a <= 0 or cols_a <= 0 or rows_b <= 0 or cols_b <= 0:
                print("Matrix dimensions must be positive.")
                continue

            break

        except ValueError:
            print("Please enter valid integer dimensions.")

    if cols_a != rows_b:
        print(
            "\nMatrix multiplication is not possible.\n"
            "The number of columns in matrix A must equal "
            "the number of rows in matrix B."
        )
        return

    matrix_a = read_matrix(rows_a, cols_a, "A")
    matrix_b = read_matrix(rows_b, cols_b, "B")

    print("\nMatrix A:")
    print(matrix_a)

    print("\nMatrix B:")
    print(matrix_b)

    start_time = time.perf_counter()

    result = np.matmul(matrix_a, matrix_b)

    end_time = time.perf_counter()

    print("\nResult of A x B:")
    print(result)

    print(f"\nExecution time: {end_time - start_time:.9f} seconds")


if __name__ == "__main__":
    main()
