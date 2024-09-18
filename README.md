```markdown
# Sorting Algorithms & Big O Notation

## Project Overview

This project focuses on implementing and understanding various sorting algorithms, as well as evaluating their time complexity using Big O notation. The goal is to learn at least four different sorting algorithms, how to choose the best algorithm based on input, and understand the difference between stable and unstable sorting algorithms.

## Learning Objectives

By the end of this project, I will be able to:
- Implement at least four different sorting algorithms.
- Understand the Big O notation and evaluate time complexity.
- Select the most appropriate sorting algorithm for a given dataset.
- Explain the characteristics of stable and unstable sorting algorithms.
- Understand the trade-offs between different algorithms in terms of efficiency and complexity.

## Requirements

- **Allowed Editors**: `vi`, `vim`, `emacs`
- **Compilation**: All files will be compiled on Ubuntu 20.04 LTS using gcc with the following options:
  - `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style**: All code will adhere to the Betty coding style.
- **No Global Variables**: Global variables are not allowed.
- **Function Limit**: No more than 5 functions per file.
- **Standard Library**: The use of standard library functions (e.g., `printf`, `puts`) is prohibited unless otherwise specified.
- **Test Files**: Test files are not mandatory to push. The project's own test files will be used during evaluation.
- **Prototype Declaration**: All function prototypes must be declared in the `sort.h` header file.

## Data Structures

The following data structures will be used:

### Doubly Linked List
```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

### Array Printing Function
```c
void print_array(const int *array, size_t size);
```

### Linked List Printing Function
```c
void print_list(const listint_t *list);
```

## Big O Notation Overview

- **O(1)**: Constant time
- **O(n)**: Linear time
- **O(n!)**: Factorial time
- **O(n^2)**: Quadratic time
- **O(log n)**: Logarithmic time
- **O(n log n)**: Linearithmic time

## Project Tasks

1. **Implementing Sorting Algorithms**: Write functions that implement sorting algorithms like `bubble sort`, `insertion sort`, `selection sort`, and others.
2. **Evaluating Time Complexity**: Understand and explain the time complexity of each algorithm using Big O notation.
3. **Selecting the Best Algorithm**: Analyze the input data and decide which sorting algorithm to use based on its time complexity and input size.

## Conclusion

This project aims to build a solid understanding of sorting algorithms, time complexity, and how to make informed decisions about algorithm selection. By completing this project, I will be better equipped to handle algorithmic challenges in real-world applications.
```
