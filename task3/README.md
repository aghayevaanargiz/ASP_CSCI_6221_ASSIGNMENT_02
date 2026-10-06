# Task 3: Matrix Multiplication

## 1. Objective

In this task, I implemented matrix multiplication in Python using NumPy arrays and in C++. I also wrote a unit test for the C++ implementation. After testing both programs, I compared their code size and execution time.

I made the programs accept the matrix dimensions and values from the user instead of using fixed matrices.

## 2. Python Implementation

For the Python implementation, I used NumPy arrays. First, I ask the user to enter the number of rows and columns for both matrices. I then check whether the matrices can be multiplied. For matrix multiplication, the number of columns in matrix A must be equal to the number of rows in matrix B.

I decided to let the user enter each row as comma separated values. After receiving the input, I convert the data into NumPy arrays.

The multiplication is performed using the `@` operator:

```python
multiplication = matrix_A @ matrix_B
```

I also added a timer around the multiplication operation so that the input time is not included in the measurement.

As an initial test, I used a 2×2 matrix and a 2×3 matrix:

```text
A = [[2, 3],
     [4, 5]]

B = [[1, 2, 3],
     [4, 5, 6]]
```

The program produced:

```text
[[14 19 24]
 [24 33 42]]
```

I also tested the program with 5×5 matrices for the execution time comparison.

## 3. C++ Implementation

For the C++ implementation, I used `vector` to store the matrices. I also made the matrix dimensions user defined, so the program is not restricted to one particular matrix size.

The program first checks whether matrix multiplication is possible. It then asks the user to enter every element of the two matrices.

Unlike the Python implementation, I implemented the multiplication itself using three nested loops. The outer two loops determine the position of the result element, while the third loop calculates the sum of the products.

The main calculation is:

```cpp
multiplication[i][j] += matrix_A[i][k] * matrix_B[k][j];
```

I first tested the C++ implementation using the same 2×2 and 2×3 matrices used in the Python implementation:

```text
A = [[2, 3],
     [4, 5]]

B = [[1, 2, 3],
     [4, 5, 6]]
```

The result was:

```text
14 19 24
24 33 42
```

I then used 5×5 matrices for the execution time comparison.

I placed the timer around the multiplication loops so that entering the matrices and printing the result were not included in the measured time.

## 4. Unit Testing

I created a separate C++ file called `matrix_multiplication_test.cpp` to test whether the multiplication function gives the expected result.

For the test, I used:

```text
A = [[1, 2],
     [3, 4]]

B = [[5, 6],
     [7, 8]]
```

I calculated the expected result manually:

```text
[[19, 22],
 [43, 50]]
```

The test compares the calculated matrix with the expected matrix. If they are equal, the program prints `Test passed!`.

The test produced:

```text
Test passed!
```

I ran the test using an online C++ compiler because I had a linker problem with my local C++ compiler when trying to create the test executable. The source code itself compiled successfully, but the local linker did not create the executable.

## 5. Code Size

I counted the lines in both main implementations using PowerShell.

The results were:

| Implementation | Lines of code |
| -------------- | ------------: |
| Python         |            68 |
| C++            |            80 |

The C++ implementation has 12 more lines than my Python implementation.

I think one reason for this difference is that NumPy allows me to perform the matrix multiplication with a single operation, while in C++ I had to explicitly write the loops that calculate every element of the resulting matrix. The C++ program also handles the matrix elements individually through user input.

However, the number of lines does not necessarily show which implementation is better. It only shows how much code I wrote for these particular implementations.

## 6. Execution Time

For the execution time comparison, I used 5×5 matrices in both programs.

Matrix A was:

```text
A = [[1, 2, 3, 4, 5],
     [1, 2, 3, 4, 5],
     [1, 2, 3, 4, 5],
     [1, 2, 3, 4, 5],
     [1, 2, 3, 4, 5]]
```

Matrix B was:

```text
B = [[5, 4, 3, 2, 1],
     [5, 4, 3, 2, 1],
     [5, 4, 3, 2, 1],
     [5, 4, 3, 2, 1],
     [5, 4, 3, 2, 1]]
```

Both implementations produced the same result:

```text
75 60 45 30 15
75 60 45 30 15
75 60 45 30 15
75 60 45 30 15
75 60 45 30 15
```

The measured execution times were:

| Implementation | Matrix size | Execution time                |
| -------------- | ----------- | ----------------------------- |
| Python + NumPy | 5×5 × 5×5   | 3.729993477463722e-05 seconds |
| C++            | 5×5 × 5×5   | 3.924e-06 seconds             |

In this experiment, the C++ implementation was faster. The measured C++ time was approximately 9.5 times smaller than the Python + NumPy time.

However, I would not consider this result enough to conclude that C++ is always faster than Python. The matrices were still relatively small, so the actual multiplication took a very short amount of time. Because of this, timing overhead and the precision of the measurement can have a noticeable effect on the result.

There is also another important difference between my two implementations. In C++, I manually implemented the multiplication using nested loops. In Python, I used NumPy's `@` operator. NumPy performs the operation using optimized compiled code, so this experiment is not simply a comparison of Python and C++ themselves.

## 7. My Observations

While doing this task, I noticed that the two implementations approach the same problem at different levels.

In my C++ implementation, I had to explicitly think about how each element of the result is calculated. For example, the value at position `[0][0]` is calculated from the first row of A and the first column of B.

In Python, NumPy hides this process behind the `@` operator. This makes the Python implementation shorter and easier to read, but the actual matrix multiplication is still being performed underneath by NumPy.

I also found that making the programs accept arbitrary matrix dimensions was more useful than writing them only for a fixed example. It allowed me to test rectangular matrices such as a 2×2 matrix multiplied by a 2×3 matrix.

The 5×5 experiment also showed that the C++ implementation took less measured time in this particular test. However, I think a larger benchmark with more repetitions would be needed before making a stronger performance conclusion.

Overall, both implementations produced the correct results for my tests. The C++ version was longer because I implemented more of the multiplication process myself, while the Python version relied more on the functionality provided by NumPy.

## 8. Files

My Task 3 files are organized as follows:

```text
task3/
├── code/
│   ├── matrix_multiplication.cpp
│   ├── matrix_multiplication.py
│   ├── matrix_multiplication_test.cpp
│   ├── GPT_GENERATED.cpp
│   └── GPT_GENERATED.py
└── README.md
```

The two main implementations are `matrix_multiplication.py` and `matrix_multiplication.cpp`. The C++ unit test is in `matrix_multiplication_test.cpp`.

The GPT generated implementations are kept separately. I will discuss them separately according to the assignment requirements.
