# Task 4: 2D Matrix Slicing

## Objective

The objective of this task is to implement 2D matrix slicing using NumPy in Python and a C++ implementation. The results of both implementations are compared to check whether they produce the same sliced matrix.

## Python/NumPy Implementation

My Python implementation first asks the user for the number of rows and columns and then reads the matrix row by row. The rows are initially stored in a Python list and then converted into a NumPy array:

```python
matrix_A = np.array(rows_of_matrix_A)
```

The slicing is performed using NumPy's built-in 2D slicing syntax:

```python
sliced_matrix = matrix_A[start_row:end_row, start_column:end_column]
```

The ending row and column indices are not included in the slice.

The implementation also checks that each entered row contains the correct number of elements.

## C++ Implementation

My C++ implementation uses a `vector<vector<int>>` to store the matrix. The number of rows and columns is provided by the user, so the matrix can have different dimensions at runtime.

Since C++ does not provide NumPy-style 2D slicing, I used nested `for` loops to select the required rows and columns:

```cpp
for (int i = start_row; i < end_row; i++) {
    for (int j = start_column; j < end_column; j++) {
        cout << matrix_A[i][j] << " ";
    }
}
```

The loop conditions make the ending row and column exclusive, matching the behavior of NumPy slicing.

## Comparison with GPT-Generated Implementations

The GPT-generated C++ implementation is more complex than mine. This is partly because the prompt specifically asked for an efficient implementation that avoids extra memory copies. It defines separate `Matrix` and `MatrixView` classes and uses a one-dimensional vector to store the matrix data. The `MatrixView` stores the slice boundaries and accesses the selected part of the original matrix without copying the elements.

The GPT-generated Python implementation is also more structured because the prompt asked for graceful handling of invalid inputs. It separates matrix input and slice-bound validation into functions and uses `try/except` to handle invalid input. It also uses NumPy's native slicing, which creates a view for this type of basic slice instead of copying the selected elements.

My implementations are simpler. My Python code directly converts the input rows into a NumPy array and applies NumPy slicing. My C++ code uses `vector<vector<int>>` and nested loops to print the selected elements. I did not implement the additional validation and view abstraction used by the generated code.

Therefore, the generated implementations follow more of the requirements from the prompt, especially input validation and avoiding copies in C++. My implementations focus on the core slicing operation and are easier to read and understand. Both approaches produced the same correct result.

## Results

Both my implementations and the GPT-generated implementations were tested using the same matrix and slicing parameters.

The matrix was:

```text
1   2   3   4   5
6   7   8   9   10
11  12  13  14  15
16  17  18  19  20
```

The selected slice was:

* Starting row: 1
* Ending row: 3
* Starting column: 1
* Ending column: 4

The resulting matrix was:

```text
7   8   9
12  13  14
```

The screenshots below show the outputs produced by my implementations.

### Python/NumPy Output

<img src="images/slicing_py_output.png" alt="Python slicing output" width="450">

### C++ Output

<img src="images/slicing_cpp_output.png" alt="C++ slicing output" width="300">

Both implementations produced the same sliced matrix. The GPT-generated implementations were also tested with the same inputs and produced the same correct result.

## Conclusion

This task demonstrated that the same 2D matrix slicing operation can be implemented in Python with NumPy and in C++. NumPy provides direct syntax for slicing a 2D array, while the C++ implementation requires explicit loops to select the required rows and columns.

The comparison with the GPT-generated implementations showed that there are multiple ways to implement the same operation. The generated implementations included more validation and abstraction, while my implementations were simpler and focused on the core slicing operation. All tested implementations produced the same expected result.
