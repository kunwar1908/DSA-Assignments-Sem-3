# 🎓 UCS301 - Data Structures: Comprehensive Lab Solutions (7 Assignments)

This repository contains the complete C++ solutions for all 7 lab assignments of the **UCS301 Data Structures** course. The project is organized to provide a clear, navigated record of fundamental data structures, algorithms, and their practical applications.

---

## 🚀 Repository Structure

The project is structured by lab assignment number, with each folder containing the relevant C++ implementation file.
---

## 🛠️ Setup and Execution

All programs are implemented in C++ and can be compiled using `g++` on any system.

1.  **Clone the repository:**
    ```bash
    git clone <YOUR_REPOSITORY_URL_HERE>
    ```

2.  **Navigate to the required assignment folder (e.g., Lab 05):**
    ```bash
    cd LabAssignment05
    ```

3.  **Compile the file:**
    ```bash
    g++ LabAssignment5_SinglyLinkedList.cpp -o lab5_exec -std=c++11
    ```
    *(Use the specific filename from the table below.)*

4.  **Run the executable:**
    ```bash
    ./lab5_exec
    ```

---

## 📜 Complete Assignment Index and Solutions

This section details the primary tasks and key concepts implemented in each of the seven lab assignments.

### 1. Lab Assignment 1: Arrays (1D & 2D)

| Q# | Task Description | C++ File | Key Concept |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for Array CRUD operations. | `LabAssignment1_Arrays.cpp` | Basic Array Management |
| **Q2** | Remove duplicate elements from an array. | `LabAssignment1_Arrays.cpp` | Uniqueness/Set Operations |
| **Q3** | Predict output of partial array initialization. | `LabAssignment1_Arrays.cpp` | Default Initialization to Zero |
| **Q4** | Reverse Array, Matrix Multiplication, Matrix Transpose. | `LabAssignment1_Arrays.cpp` | 1D and 2D Array Traversal |
| **Q5** | Find sum of every row and every column in a 2D array. | `LabAssignment1_Arrays.cpp` | Nested Loop Traversal |

***

### 2. Lab Assignment 2: Advanced Arrays, Search, and Sort

| Q# | Task Description | C++ File | Key Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Implement **Binary Search** ($O(\log n)$). | `LabAssignment2_AdvancedArrays.cpp` | Divide and Conquer |
| **Q2** | Code the **Bubble Sort** algorithm. | `LabAssignment2_AdvancedArrays.cpp` | Repeated Swapping ($O(n^2)$) |
| **Q3** | Find a **Missing Number** in a sorted array (both $O(n)$ and $O(\log n)$ methods). | `LabAssignment2_AdvancedArrays.cpp` | Summation (Linear) & Binary Search |
| **Q4** | String Programs (Concatenate, Reverse, Delete Vowels, Sort, Case Convert). | `LabAssignment2_AdvancedArrays.cpp` | `std::string` and `std::algorithm` |
| **Q5** | Implement **efficient space storage** for special matrices (Triangular, Symmetric, etc.). | `LabAssignment2_AdvancedArrays.cpp` | Space Complexity Analysis ($O(n), O(n^2/2)$) |
| **Q6** | Sparse Matrix Operations (Transpose) using **Triplet** representation. | `LabAssignment2_AdvancedArrays.cpp` | Triplet Format (Row, Col, Value) |
| **Q7** | Write a program to count the number of **Inversions** in an array. | `LabAssignment2_AdvancedArrays.cpp` | $O(n^2)$ Brute Force Count |
| **Q8** | Count the total number of **distinct elements** in an array. | `LabAssignment2_AdvancedArrays.cpp` | Sort and `std::unique` |

***

### 3. Lab Assignment 3: Stacks

| Q# | Task Description | C++ File | Key Concept |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for Array-based Stack operations (`push`, `pop`, `peek`, etc.). | `LabAssignment3_Stacks.cpp` | LIFO (Last-In, First-Out) |
| **Q2** | Reverse a given string using a **STACK**. | `LabAssignment3_Stacks.cpp` | Stack Reversal Application |
| **Q3** | Check if an expression has **balanced parentheses**. | `LabAssignment3_Stacks.cpp` | Matching Brackets |
| **Q4** | Convert an **Infix** expression into a **Postfix** expression. | `LabAssignment3_Stacks.cpp` | Operator Precedence Rules |
| **Q5** | Program for the **evaluation** of a **Postfix** expression. | `LabAssignment3_Stacks.cpp` | Stack for Operands |

***

### 4. Lab Assignment 4: Queues

| Q# | Task Description | C++ File | Key Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for **Simple Queues** using an Array. | `LabAssignment4_Queues.cpp` | FIFO (First-In, First-Out) |
| **Q2** | Menu-driven program for **Circular Queues** using an Array. | `LabAssignment4_Queues.cpp` | Modulo Arithmetic for Wraparound |
| **Q3** | Program to **interleave** the first half of a queue with the second half. | `LabAssignment4_Queues.cpp` | Queue + Auxiliary Stack |
| **Q4** | Program to find the **first non-repeating character** in a string stream. | `LabAssignment4_Queues.cpp` | Queue + Frequency Map |
| **Q5** | Implement a **Stack** using **Two Queues** and **One Queue**. | `LabAssignment4_Queues.cpp` | Data Structure Simulation |

***

### 5. Lab Assignment 5: Singly Linked Lists (SLL)

| Q# | Task Description | C++ File | Key Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for SLL operations (Insertion, Deletion, Search, Display). | `LabAssignment5_SinglyLinkedList.cpp` | Head Pointer Manipulation |
| **Q2** | Count occurrences of a key and **delete all** instances. | `LabAssignment5_SinglyLinkedList.cpp` | Robust Deletion Handling |
| **Q3** | Program to find the **middle node** of a linked list. | `LabAssignment5_SinglyLinkedList.cpp` | **Slow and Fast Pointer** (Tortoise and Hare) |
| **Q4** | Program to **reverse** a linked list. | `LabAssignment5_SinglyLinkedList.cpp` | Iterative Reversal (`prev`, `current`, `next`) |

***

### 6. Lab Assignment 6: Doubly and Circular Linked Lists

| Q# | Task Description | C++ File | Key Concept |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for **DLL** and **CLL** operations (Insert/Delete Anywhere, Search). | `LabAssignment6_DLL_CLL.cpp` | Two-way and Circular Linking |
| **Q2** | **Display** all node values in a **CLL**, repeating the head node value at the end. | `LabAssignment6_DLL_CLL.cpp` | CLL Traversal Logic |
| **Q3** | Program to find the **size** of a DLL and a CLL. | `LabAssignment6_DLL_CLL.cpp` | Traversal Counting |
| **Q4** | Check if a **Doubly Linked List** of characters is a **palindrome**. | `LabAssignment6_DLL_CLL.cpp` | Two-Pointer (Head and Tail) Traversal |
| **Q5** | Check if a linked list is a **Circular Linked List** or not. | `LabAssignment6_DLL_CLL.cpp` | **Floyd's Cycle Detection** (Slow/Fast Pointers) |

***

### 7. Lab Assignment 7: Sorting Algorithms

| Q# | Task Description | C++ File | Time Complexity |
| :---: | :--- | :--- | :---: |
| **Q1** | Implement **Selection, Insertion, Bubble, Merge, and Quick Sort**. | `LabAssignment7_Sorting.cpp` | $O(n^2)$ and $O(n \log n)$ |
| **Q2** | Implement the **Improved Selection Sort** (Dual Selection Sort - finding min/max in one pass). | `LabAssignment7_Sorting.cpp` | $O(n^2)$ |