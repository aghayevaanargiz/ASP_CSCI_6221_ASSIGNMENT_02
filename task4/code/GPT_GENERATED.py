import numpy as np


def read_matrix(rows, cols):
    """Read a matrix from user input."""
    matrix = []

    print(f"\nEnter the matrix ({rows} x {cols}):")

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


def read_slice_bounds(rows, cols):
    """Read and validate slicing bounds from the user."""

    while True:
        try:
            row_start = int(input("row_start: "))
            row_end = int(input("row_end: "))
            col_start = int(input("col_start: "))
            col_end = int(input("col_end: "))

            if not (0 <= row_start <= row_end <= rows):
                print(
                    f"Invalid row range. "
                    f"Use 0 <= row_start <= row_end <= {rows}."
                )
                continue

            if not (0 <= col_start <= col_end <= cols):
                print(
                    f"Invalid column range. "
                    f"Use 0 <= col_start <= col_end <= {cols}."
                )
                continue

            if row_start == row_end or col_start == col_end:
                print("The slice cannot have zero rows or columns.")
                continue

            return row_start, row_end, col_start, col_end

        except ValueError:
            print("Please enter integer slice bounds.")


def main():
    print("2D Matrix Slicing using NumPy")
    print("==============================")

    while True:
        try:
            rows = int(input("Number of rows: "))
            cols = int(input("Number of columns: "))

            if rows <= 0 or cols <= 0:
                print("Matrix dimensions must be positive.")
                continue

            break

        except ValueError:
            print("Please enter valid integer dimensions.")

    matrix = read_matrix(rows, cols)

    print("\nOriginal matrix:")
    print(matrix)

    print("\nEnter slice bounds.")
    print("The end indices are exclusive, following Python slicing rules.")

    row_start, row_end, col_start, col_end = read_slice_bounds(rows, cols)

    # NumPy slicing creates a view rather than copying the selected data.
    sliced_matrix = matrix[row_start:row_end, col_start:col_end]

    print("\nSliced matrix:")
    print(sliced_matrix)

    print("\nSlice shape:")
    print(sliced_matrix.shape)

    print("\nDoes the slice share memory with the original matrix?")
    print(np.shares_memory(matrix, sliced_matrix))


if __name__ == "__main__":
    main()
