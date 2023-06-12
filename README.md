# Push_swap

This project is part of the curriculum at 42 school and aims to provide a sorting algorithm using two stacks. The project involves creating a program that receives a stack of integers as input and outputs a series of instructions to sort the stack using various predefined operations.

## Table of Contents

- [Project Description](#project-description)
- [Installation and Usage](#installation-and-usage)
- [Algorithm](#algorithm)

## Project Description

The "push_swap" project focuses on developing an efficient sorting algorithm using two stacks, namely "Stack A" and "Stack B." The goal of the project is to output instructions that sort the elements in "Stack A" in ascending order.

The algorithm achieves the sorting by performing a series of operations, including:

- **Swap (sa/sb)**: Swaps the top two elements of "Stack A" or "Stack B," respectively.

- **Push (pa/pb)**: Moves the top element from "Stack A" to "Stack B" (pb) or from "Stack B" to "Stack A" (pa).

- **Rotate (ra/rb)**: Shifts all elements in "Stack A" (ra) or "Stack B" (rb) upward by one. The top element becomes the bottom element.

- **Reverse Rotate (rra/rrb)**: Shifts all elements in "Stack A" (rra) or "Stack B" (rrb) downward by one. The bottom element becomes the top element.

The sorting algorithm intelligently utilizes these operations to arrange the elements in "Stack A" in ascending order while leveraging "Stack B" for temporary storage and sorting.

## Installation and Usage

To install and run the project, follow these steps:

1. Clone the repository to your local machine:

```
git clone <repo url> push_swap
```

2. Navigate to the project directory:

```
cd push_swap
```

3. Build the program:

```
make
```

4. Run the program with a list of integers as arguments:

```
./bin/push_swap 4 2 5 1 3
```

The provided integers represent the elements of "Stack A" in the order from top to bottom.

The program will output a series of instructions that, when executed, will sort "Stack A" in ascending order.

For example, the program might output:

```
sa
ra
pb
...
```



_<u>Checkers for Validating Sorting</u>: Checkers are designed to verify the correctness of the sorting algorithm implemented in the 'push_swap' program. They can be found in the `checkers` folder of this repository._

```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
OK $>
```

## Algorithm

The "push_swap" program implements a sorting algorithm based on a combination of sorting techniques, including divide and conquer. The specific algorithm used in this implementation is a variation of the QuickSort algorithm.

The algorithm divides the initial stack into smaller sub-stacks and recursively sorts them. It takes advantage of the two stacks to perform the sorting efficiently and minimize the number of operations required.