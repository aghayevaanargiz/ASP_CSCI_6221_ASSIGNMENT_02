# Task 2: Investigating Python Object Memory Size

## 1. Objective

The purpose of this experiment is to investigate how Python reports the memory size of tuples and lists using the __sizeof__() method. Although both data structures can store multiple objects they have different characteristics and internal representations. The experiment examines whether these differences can be observed through the reported object size and how the size changes as the number of elements increases.

## 2. Initial Assumption

Before doing the experiment, I expect the tuple and list to have different sizes even if they contain the same elements. I also expect the list size to change differently because lists are mutable, so Python may allocate some extra space for future changes. Tuples are different because their structure cannot be changed after they are created. By comparing the number of elements with the reported size, I hope to get a better idea of how lists and tuples are stored internally.

## 3. Experimental Setup

### 3.1 Python Environment

The experiment was conducted using CPython 3.13.6 on a 64-bit Windows environment. The Python implementation was verified using the `sys` module.


