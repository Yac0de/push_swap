# Push\_swap Project

---

## Table of Contents

1. [**Project Overview**](#1-project-overview)
2. [**How It Works**](#2-how-it-works)
3. [**Performance Goals**](#3-performance-goals)
4. [**Algorithm Explanation**](#4-algorithm-explanation)
   - [Initialization and Input Validation](#initialization-and-input-validation)
   - [Filling Stack A](#filling-stack-a)
   - [Checking If Already Sorted](#checking-if-already-sorted)
   - [Sorting Process](#sorting-process)
     - [Updating Stack Metadata](#updating-stack-metadata)
     - [Presorting Elements](#presorting-elements)
     - [Sorting Three Elements](#sorting-three-elements)
     - [Optimization with Reintegrating Elements Efficiently](#optimization-with-reintegrating-elements-efficiently)
5. [**How to Use**](#5-how-to-use)
6. [**Testing with Visualizer**](#testing-with-visualizer)
7. [**Bonus Features**](#bonus-features)
   - [The "checker" Program](#the-checker-program)
     - [Features](#features)
     - [Installation](#installation)
     - [Usage](#usage)
     - [Example Outputs](#example-outputs)
   - [Detailed Algorithm Explanation for Bonus](#detailed-algorithm-explanation-for-bonus)
     - [Filling `stack_a` for the Checker](#filling-stack_a-for-the-checker)
     - [Reading and Executing Instructions](#reading-and-executing-instructions)
     - [Verifying the Result](#verifying-the-result)

---

## 1. Project Overview

The **Push\_swap** project challenges you to sort a stack of integers using a minimal set of operations. With two stacks (`a` and `b`) and a restricted instruction set, the goal is to produce the shortest sequence of commands to sort the input. This project is a practical exercise in algorithmic thinking, optimization, and complexity analysis.

---

## 2. How It Works

You manipulate the stacks using the following instructions:

- **sa / sb**: Swap the top two elements of stack `a` or `b`.
- **ss**: Perform `sa` and `sb` simultaneously.
- **pa / pb**: Push the top element of stack `b` to `a` or vice versa.
- **ra / rb**: Rotate stack `a` or `b` upwards.
- **rr**: Perform `ra` and `rb` simultaneously.
- **rra / rrb**: Reverse rotate stack `a` or `b` downwards.
- **rrr**: Perform `rra` and `rrb` simultaneously.

The initial state consists of stack `a` filled with unsorted integers, while stack `b` is empty. The objective is to sort stack `a` in ascending order using the fewest commands.

---

## 3. Performance Goals

- **Minimalistic Validation**: Sort 100 random integers in fewer than 700 operations (on average).
- **Optimal Validation**: Sort 500 random integers in fewer than 5,500 operations.

The performance is evaluated by comparing the number of operations your program generates against these benchmarks.

---

## 4. Algorithm Explanation

### Initialization and Input Validation

The program begins by parsing and validating the input. Below are the key steps:

1. **Handling Input Arguments**:
   If the input is provided as a single string (e.g., `"4 3 2 1"`), the program splits it into individual numbers using `ft_split`.

2. **Input Validation**:
   The `check_input` function ensures the input follows these rules:

   - Each value is a valid number (`ft_isnumber`).
   - Each value fits within the range of a 32-bit integer (`ft_isint`).
   - No duplicate values exist in the input (`is_unique`).

3. **Stack Initialization**:
   Two stacks (`stack_a` and `stack_b`) are initialized with default values. This is handled by the `init_stacks` function.

This setup ensures that the program starts with clean and valid data structures.

### Filling Stack A

Once the stacks are initialized, `stack_a` is populated with the input values. This is done through the `fill_stack_a` function:

1. **Handling Input Length**:
   If the input is passed as a single argument, its length is determined using `ft_arraylen`, and parsing starts from the first value.

2. **Dynamic Allocation**:
   For each value:

   - Allocate memory for a new integer.
   - Convert the string to an integer using `ft_atoi`.
   - Add the new integer to the stack using `ft_stackadd_back`.

3. **Error Handling**:
   If memory allocation fails, the program cleans up both stacks and exits with an error message.

This ensures that `stack_a` is populated with the correct values, ready for sorting.

### Checking If Already Sorted

Before performing any sorting operations, the program checks if `stack_a` is already sorted in ascending order. This is handled by the `is_sorted` function:

1. **Iterating Through the Stack**:
   Starting from the top node, the program compares each element with the next.

2. **Validation**:

   - If any element is greater than the next, the stack is not sorted, and the function returns `0`.
   - If all elements are in order, the function returns `1`.

3. **Early Exit**:
   If the stack is already sorted, the program frees all allocated memory and exits without further operations:

This step prevents unnecessary computations when the input is already sorted.

### Sorting Process

#### Updating Stack Metadata

The `update_stacks` function is a critical utility that ensures the stacks' metadata (size, minimum, and maximum values) remains accurate throughout the sorting process:

1. **Update Size**:

   - The size of `stack_a` and `stack_b` is recalculated using `ft_stacksize`.

2. **Update Minimum and Maximum**:

   - For non-empty stacks, the `find_min` and `find_max` functions are used to identify the smallest and largest elements, respectively.

This function is called multiple times throughout the sorting process to ensure that the program always operates on up-to-date information.

#### Presorting Elements

The `presort` function organizes `stack_a` by dividing its elements into smaller groups (tertiles) and pushing certain values to `stack_b`. The goal is to leave only three elements in `stack_a` while reducing the number of operations needed later during sorting. This method is more efficient than simply transferring all elements to `stack_b`.

1. **Finding Key Values**:

   - `find_third_max` identifies the third largest value in `stack_a`, which helps in determining which values should remain.
   - `find_tertiles` splits the range of values in `stack_a` into three groups (tertiles) by sorting the elements and selecting thresholds.

2. **Pushing Values to stack\_b**:

   - Values lower than the second tertile are pushed to `stack_b` while rotating `stack_a` as necessary to maintain order.
   - Remaining values less than the third maximum are then pushed to `stack_b`, leaving `stack_a` with three elements.

By strategically using tertiles, `presort` reduces the size of `stack_a` while preparing the elements in a way that minimizes the operations required during the final sorting steps. After this process, `stack_a` contains exactly three elements, which are the largest values left in the stack. Meanwhile, `stack_b` contains values grouped based on their relative size: the smallest values (below the second tertile) are pushed first, followed by values below the third maximum. This grouping ensures that `stack_b` is partially structured to simplify reintegration into `stack_a` during the next phase.

#### Sorting Three Elements

After the `presort` step, the function `sort_three_numbers_a` is used to sort the three remaining elements in `stack_a`. This ensures `stack_a` is fully ordered before elements from `stack_b` are reintegrated.

#### Reintegration of Elements from Stack B

The next critical step is reintegrating elements from `stack_b` into `stack_a`. This is achieved through the following logic:

1. **Finding the Optimal Element to Push**:

   - The function `find_min_cost_number` calculates the cost of reintegrating each element from `stack_b` into its correct position in `stack_a`.
   - Cost is determined by considering both the rotations required in `stack_a` and `stack_b`.
   - The element with the minimal cost is selected.

2. **Calculating Cost**:

   - `calculate_cost_to_push` computes the total cost by:
     - Using `calculate_cost_a` to determine how many rotations are needed in `stack_a` to prepare for insertion.
     - Using `calculate_cost_b` to compute the rotations needed to bring the target element to the top of `stack_b`.

3. **Execution**:

   - Once the optimal element is identified, it is pushed from `stack_b` to `stack_a` using the function `move`.

4. **Repetition Until Completion**:

   - The process is repeated until all elements from `stack_b` are reintegrated into `stack_a`.

#### Final Adjustment of Stack A

Once all elements have been reintegrated into `stack_a`, the smallest element is placed at the top to complete the sorting process. This is done using the function `place_min_number_on_top_a`:

1. **Finding the Position of the Smallest Element**:

   - The position of the smallest value in `stack_a` is determined using `find_position`.

2. **Rotating Stack A**:

   - If the smallest element is in the first half of the stack, normal rotations (`ra`) are performed.
   - If it is in the second half, reverse rotations (`rra`) are used.

3. **Completion**:

   - After this step, `stack_a` is fully sorted in ascending order.

By ensuring that the smallest element is at the top, the sorting process is finalized efficiently with minimal operations.\
\
To finalize the program and ensure no memory leaks occur, both stack\_a and stack\_b are freed using the free\_stack function.

---

## 5. How to Use

### Compilation

Ensure you have `cc` installed, then compile the project using the provided Makefile:

```bash
make
```

### Running the Program

To sort a stack:

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

### Testing Performance

For minimal validation (average performance):

- Sort 100 random integers in fewer than 700 operations.

For optimal validation (bonus eligibility):

- Sort 500 random integers in fewer than 5,500 operations.

You can test the number of operations using randomly generated inputs:

#### Generating 100 Random Numbers

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

#### Generating 500 Random Numbers

```bash
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

This will generate 100 or 500 random numbers, shuffle them, and pass them as input to `push_swap`.\
The `wc -l` command counts the number of operations used.

---

## Testing with Visualizer

You can also use a visualizer to better understand and debug your program. The [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) provides an interactive way to see your sorting algorithm in action.

### Installation

1. Clone the repository into the directory where your `push_swap` project is located:
   ```bash
   git clone https://github.com/o-reo/push_swap_visualizer.git
   ```

2. Install the required dependencies (for Debian-based systems):
   ```bash
   sudo apt-get update
   sudo apt-get install cmake g++ clang libgl1-mesa-dev libglu1-mesa-dev libx11-dev libxrandr-dev libudev-dev libfreetype-dev
   ```

3. Navigate to the `push_swap_visualizer` directory, create a build directory, and compile:
   ```bash
   cd push_swap_visualizer
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the visualizer:
   ```bash
   ./bin/visualizer
   ```

### Usage

1. **Set up the visualizer:**
   - Choose the size of the `push_swap` input with the slider (optional).
   - Shuffle the input (optional) or manually input values.
   - Set the path to your `push_swap` program (absolute or relative).

2. **Visualize the algorithm:**
   - Compute the sort commands and load them into the visualizer.
   - Start the animation to see the steps.
   - Use the controls to adjust speed, pause, or step through the algorithm.

This tool provides an excellent way to debug your implementation and visually analyze the performance of your sorting algorithm.

## Bonus Features

### Table of Contents
- The "checker" Program
  - Features
  - Installation
  - Usage
  - Example Outputs
- Detailed Algorithm Explanation for Bonus
  - Filling `stack_a` for the Checker
  - Reading and Executing Instructions
  - Verifying the Result

As part of the bonus implementation, a custom checker program has been created to verify the correctness of the generated instructions.

### The "checker" Program

This program takes a stack of integers as input, executes the sorting instructions generated by `push_swap`, and verifies the result. Below are the key features and usage instructions:

#### Features

- Reads sorting instructions from standard input.
- Applies the instructions to the stack and verifies the result.
- Outputs:
  - `OK` if `stack_a` is sorted and `stack_b` is empty.
  - `KO` if the stack is not correctly sorted.
  - `Error` if invalid instructions or inputs are provided.

#### Installation

The checker program is included as part of the bonus section. Use the following command to build it:

```bash
make bonus
```

#### Usage

1. Run the `push_swap` program to generate sorting instructions:
   ```bash
   ./push_swap 3 2 1 0 > commands.txt
   ```

2. Pipe the instructions to the `checker` program:
   ```bash
   ./checker 3 2 1 0 < commands.txt
   ```

3. Test manually by entering instructions interactively:
   ```bash
   ./checker 3 2 1 0
   rra
   pb
   sa
   rra
   pa
   <Ctrl+D>
   ```
   Pressing `Ctrl+D` signals the end of input, and the program will display the result.

4. Example outputs:
   - **Correctly sorted stack:**
     ```
     OK
     ```
   - **Incorrectly sorted stack:**
     ```
     KO
     ```
   - **Invalid input:**
     ```
     Error
     ```

### Detailed Algorithm Explanation for Bonus

The bonus implementation follows a similar structure to the main sorting algorithm, with additional functionality to validate the results:

#### Filling `stack_a` for the Checker

The function `fill_stack_a_b` is responsible for populating `stack_a` with the input values:

1. **Handling Input Length**:
   If the input is passed as a single argument, its length is determined using `ft_arraylen_b`, and parsing starts from the first value.

2. **Dynamic Allocation**:
   For each value:

   - Allocate memory for a new integer.
   - Convert the string to an integer using `ft_atoi`.
   - Add the new integer to the stack using `ft_stackadd_back_b` and `ft_stacknew_b`.

3. **Error Handling**:
   If memory allocation fails, both stacks are freed, and the program exits with an error message.

This ensures that `stack_a` is populated correctly for the checker program.

#### Reading and Executing Instructions

The `get_instruction_b` function reads the sorting instructions from standard input and applies them to the stacks:

1. **Reading Instructions**:
   - Instructions are read line by line using `get_next_line`.
   - Each instruction is passed to `handle_instruction_b` for validation and execution.

2. **Validating and Executing Instructions**:
   - Supported instructions (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, `rr`, `rrr`) are mapped to their corresponding stack operations.
   - If an invalid instruction is encountered, the `error_instructions_b` function is called, which:
     - Outputs an `Error` message.
     - Frees all allocated memory.
     - Exits the program.

#### Verifying the Result

The `end_message_b` function checks the final state of the stacks:

1. **Validation**:
   - If `stack_a` is sorted in ascending order and `stack_b` is empty, the program outputs `OK`.
   - Otherwise, it outputs `KO`.

2. **Sorting Validation**:
   - The `is_sorted_b` function iterates through `stack_a` to ensure all elements are in ascending order.

By combining these steps, the bonus checker program ensures that the sorting algorithm is not only functional but also robust and reliable.
