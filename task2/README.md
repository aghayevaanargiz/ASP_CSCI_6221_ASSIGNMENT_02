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
The outputs for both are 48 and 24 correspondingly for Tuple and List. The tuple and list contain the same three values, but their reported sizes are different. The tuple reports 48 bytes, while the list reports 72 bytes. Therefore, the list reports 24 bytes more memory than the tuple in this experiment.

I will create table to run this on different number of elements and record the outputs correspondingly:

| Number of elements | Size of Tuple | Size of List |
|---------|------|------|
| 0    |   | |
| 1    |   ||
| 2    |   ||
| 3    | 48  | 72 |



