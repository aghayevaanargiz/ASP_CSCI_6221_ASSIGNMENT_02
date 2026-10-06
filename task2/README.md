# Task 2: Investigating Python Object Memory Size

## 1. Objective

The purpose of this experiment is to investigate how Python reports the memory size of tuples and lists using the __sizeof__() method. Although both data structures can store multiple objects they have different characteristics and internal representations. The experiment examines whether these differences can be observed through the reported object size and how the size changes as the number of elements increases.

## 2. Initial Assumption

Before doing the experiment, I expect the tuple and list to have different sizes even if they contain the same elements. I also expect the list size to change differently because lists are mutable, so Python may allocate some extra space for future changes. Tuples are different because their structure cannot be changed after they are created. By comparing the number of elements with the reported size, I hope to get a better idea of how lists and tuples are stored internally.

## 3. Experimental Setup

### 3.1 Python Environment

The experiment was conducted using CPython 3.13.6 on a 64-bit Windows environment. The Python implementation was verified using the `sys` module.

```python
import sys

print(sys.version)
print(sys.implementation.name)
```

The output was:

```text
3.13.6 (tags/v3.13.6:4e66535, Aug  6 2025, 14:36:00) [MSC v.1944 64 bit (AMD64)]
cpython
```
### 3.2 Basic Tuple and List Comparison
The first experiment compares a tuple and a list containing the same three integer values.

```python
tpl = (1, 2, 3)
lst = [1, 2, 3]

print("Tuple:", tpl.__sizeof__())
print("List:", lst.__sizeof__())
```

I will create table to run this on different number of elements and record the outputs correspondingly:

| Number of elements | Size of Tuple | Size of List |
|---------|------|------|
| 0    | 24 | 40 |
| 1    | 32 | 48 |
| 2    | 40 | 56 |
| 3    | 48 | 72 |
| 4    | 56 | 72 |
| 5    | 64 | 88 |
| 6    | 72 | 88 |
| 7    | 80 | 104  |
| 8    | 88 | 104  |
| 9    | 96 |120  |
| 10   | 104 | 120 |

**My initial observation:** Looking at the tuple column, as the number of elements increases by one, the reported size of the tuple also increases by 8 bytes each time. The same pattern appeared in the list column as well. Oh, no does it really? Actually, after looking more carefully at the results, I noticed a different pattern. For the list, the reported size remains the same for some consecutive numbers of elements. For example, the size is 72 bytes for both 3 and 4 elements, and 88 bytes for both 5 and 6 elements. Another interesting observation is that the list size initially increases by 8 bytes per element, but after 3 elements, its size does not increase with every additional element. This makes me question why the list behaves differently from the tuple.




