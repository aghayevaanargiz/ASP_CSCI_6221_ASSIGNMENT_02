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

### 3.2.1 The First Experiment 
The first experiment compares a tuple and a list containing the same number of integer values. I will create table to run this on different number of elements and record the outputs correspondingly. 

```python
tpl = (1, 2, 3)
lst = [1, 2, 3]

print("Tuple:", tpl.__sizeof__())
print("List:", lst.__sizeof__())
```


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

> I have a question at this point in my mind. Does the list size change every time an element is added or does Python reserve some additional space for future elements?

### 3.2.2 The Second Experiment 

To investigate the question above further, I added elements to the same list one by one and recorded its reported size after each insertion.


```python
lst = []

for i in range(11):
    print(i, lst.__sizeof__())
    lst.append(i)
```

output is 
```text
0 40                  
1 72                             
2 72                
3 72
4 72
5 104
6 104
7 104
8 104
9 168
10 168
```
**My observation**. Great, the results show that the list does not increase its reported size every time a new element is added. The empty list already reports 40 bytes and after adding the first element the reported size becomes 72 bytes. It then remains 72 bytes as elements are added until the fifth element when it increases to 104 bytes. A similar pattern can be observed between the fifth and eighth elements. This suggests that the list may have additional storage available beyond the elements currently stored in it. Therefore, the results support the idea that list growth involves allocating additional space rather than increasing the reported size for every individual element.

## 4. Explanation 
### 4.1 What does __sizeof__() measure?
According to the [Python Official Documentation](https://docs.python.org/3/library/sys.html) the size reported by these experiments represents the memory directly associated with that object and does not include the memory used by objects that it refers to. The documentation also explains that sys.getsizeof() calls the object's __sizeof__() method. Therefore, in this experiment, the values returned by __sizeof__() should be understood as the size of the tuple or list object itself, rather than the total memory used by all of its elements.

Putting technical language aside, this is simply means when the tuple (1, 2, 3) reports 48 bytes, this does not mean that the three integer objects together occupy 48 bytes. The result describes the memory associated with the tuple object. 

### 4.2 Why does the tuple size increase consistently?

So, as the [Python Official Documentation](https://docs.python.org/3/library/sys.html) confirms, tuples are immutable, meaning that their elements cannot be changed after the tuple is created. Intuitively, this also explains why a tuple does not need additional storage for potential future elements. The size of a tuple is fixed when it is created, so Python already knows how much space is needed for its elements. This also helps explain why lists support operations such as append(), while tuples do not.

Another meaningful question is why the reported size increases by 8 bytes each time another element is added to the tuple. In CPython 3.13 on a 64 bit system, a typical Python `int` object starts at 28 bytes. If the complete integer object itself was stored inside the tuple, then adding one integer would mean that the size of the tuple should increase by around 28 bytes. However, in our experiment, it increases by only 8 bytes. This suggests that the integer itself is not stored directly inside the tuple. Instead, the tuple stores a reference to the integer object, and this reference corresponds to the 8 byte increase that we observe.


