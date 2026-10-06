# Task 3: Matrix Multiplication

## 1. Objective

In this task, I implemented matrix multiplication in Python using NumPy arrays and in C++. I also wrote unit tests for the C++ implementation. After testing both programs, I compared their code size and execution time.

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

I created a separate C++ file called `matrix_multiplication_test.cpp` to test whether the matrix multiplication function gives the expected results.

I used two test cases with different matrix sizes.

### Test 1

For the first test, I used two 2×2 matrices:

```text
A = [[1, 2],
     [3, 4]]

B = [[5, 6],
     [7, 8]]
```

The expected result was:

```text
[[19, 22],
 [43, 50]]
```

### Test 2

For the second test, I used a 2×2 matrix and a 2×3 matrix:

```text
A = [[2, 3],
     [4, 5]]

B = [[1, 2, 3],
     [4, 5, 6]]
```

The expected result was:

```text
[[14, 19, 24],
 [24, 33, 42]]
```

For each test, the calculated result is compared with the expected result. If they are equal, the test prints that the test passed.

The tests produced:

```text
Test 1 passed!
Test 2 passed!
```

This checks the multiplication logic with both square and rectangular matrices.

I ran the test using an online C++ compiler because I had a linker problem with my local C++ compiler when trying to create the test executable. The source code itself compiled successfully, but the local linker did not create the executable.

## 5. Code Size

I counted the lines in both main implementations using PowerShell.

The results were:

| Implementation | Lines of code |
| -------------- | ------------: |
| Python         |            68 |
| C++            |            105|

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

The two main implementations are `matrix_multiplication.py` and `matrix_multiplication.cpp`. The C++ unit tests are in `matrix_multiplication_test.cpp`.

The test file contains two test cases and compares the calculated results with manually determined expected results.

The GPT generated implementations are kept separately. I discuss them separately according to the assignment requirements.

## 9. ChatGPT Implementation

After completing my own implementations, I asked ChatGPT to implement the same matrix multiplication task. I saved the generated Python and C++ implementations separately as `GPT_GENERATED.py` and `GPT_GENERATED.cpp`.

For the Python version, ChatGPT used NumPy and the `np.matmul()` function. It also organized the code into a separate `read_matrix()` function and a `main()` function. The implementation includes more input validation than my version, such as checking for positive matrix dimensions and invalid numeric input.

For the C++ version, ChatGPT divided the program into separate functions for reading a matrix, multiplying matrices, and printing a matrix. It used `std::vector<double>` to store the matrices and implemented the multiplication using three nested loops.

The main difference I noticed is that the ChatGPT implementations are more structured and contain more input validation. My implementations are simpler and more direct. For example, my C++ multiplication is written directly inside the `main()` function, while the ChatGPT version puts the multiplication in a separate `multiply()` function.

Another difference is the loop order in the C++ implementations. My implementation uses the order `i`, `j`, `k`, while the ChatGPT implementation uses `i`, `k`, `j`. Both calculate the same matrix multiplication result, but they organize the operations differently.

### Prompting

My prompt asked it to implement matrix multiplication in Python using NumPy and in C++, while keeping the programs dynamic rather than using fixed matrix sizes.

I specifically asked it to:

- allow the user to enter the matrix dimensions and values;
- check whether the matrices can be multiplied;
- implement matrix multiplication using NumPy in Python;
- implement the multiplication using loops in C++;
- include execution time measurement;
- keep the code general rather than hardcoding the test matrices;
- write clean and readable code.

I then tested the generated implementations using the same type of inputs as my own implementations and compared their structure and approach with my code.

This allowed me to see how the same requirements could be implemented differently. ChatGPT focused more on modular functions and input validation, while my implementation was more direct and simpler.

### Comparison

Comparing the implementations helped me notice that there are different ways to structure the same solution. My implementation focuses on keeping the code relatively simple and showing the multiplication process directly. The ChatGPT implementation focuses more on separating the program into functions and handling different input cases, which is more modular than my structure.

I think the ChatGPT version is more modular, especially the C++ version, because the multiplication can be called separately from the input and output parts. However, my implementation was easier for me to write and understand while I was learning how the matrix multiplication works.

The ChatGPT-generated code also uses more advanced C++ features such as `std::size_t`, `const` references, exceptions, and range-based loops. This makes the code more structured, but it also makes it somewhat more complex than my implementation.
