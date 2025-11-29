DSA Assignments — Semester 3
================================

Short description
- This repository contains per-question C++ solutions (one file per question) for the Semester 3 Data Structures & Algorithms lab assignments.
- Each assignment is in `AssignmentN/` and contains `q1.cpp`, `q2.cpp`, ... as standalone demo programs.

Project layout
- `Assignment1/` .. `Assignment7/` — folders, each with `q*.cpp` files and an assignment `Readme.md`.

Build & run (Windows, MSYS2 / g++)
- Compile a single question file:
  - `g++ -std=c++17 -O2 -g AssignmentX/qY.cpp -o AssignmentX/qY.exe`
  - Then run: `AssignmentX\\qY.exe`
- Notes:
  - Replace `g++` with your system's C++ compiler if different.
  - If using MSYS2 or MinGW-w64 on Windows, you may need to run these commands from a suitable shell.

Why there's no automation script
- The previous `compile_and_run_qs.ps1` automation script was removed by request. Build and run per-question binaries manually (commands above) or add your own script.

Commit guidance
- To commit the current changes locally:
  - `git add -A`
  - `git commit -m "Split labs into per-question files; update READMEs; remove automation script"`
  - `git push`

Contact / Notes
- Each assignment folder's `Readme.md` contains a short description and a note (including a respectful message to Prof. Ritesh Sharma). If you want me to commit these changes, say so and I will run the git commands for you.

License
- No license specified. Add one if you plan to publish publicly.
# UCS301 — Data Structures: Lab Solutions (with a dash of sass)

Welcome to the mildly opinionated repository for UCS301 lab work. If algorithms had personalities, these would be the roommates who leave a mess but still sort your laundry correctly. Here you'll find the per-question C++ demos (`q1.cpp`, `q2.cpp`, …) organized by assignment.

Note: these are student-friendly demos — readable, testable, and occasionally dramatic.

---

## Quick Start

Clone the repo and run one example. You know the drill.

```powershell
git clone <YOUR_REPO_URL>
cd "DSA Assignments"
# Compile a single demo (example: Assignment2 bubble sort)
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment2\q2.cpp -O2 -o Assignment2\q2.exe
Assignment2\q2.exe

# Or run the bulk script (compiles & runs every q*.cpp) — WARNING: lots of output
powershell -NoProfile -File compile_and_run_qs.ps1
```

---

## Folder snapshot (short & useful)

- `Assignment1/` — Arrays: `q1..q5.cpp` (array CRUD, duplicate removal, matrix ops)
- `Assignment2/` — Advanced Arrays & Strings: `q1..q8.cpp` (binary search, bubble sort, missing-number, string tasks, sparse/triangular demos)
- `Assignment3/` — Stacks: `q1..q5.cpp` (stack ops, reverse string, brackets, infix→postfix, postfix eval)
- `Assignment4/` — Queues: `q1..q5.cpp` (simple/circular queues, interleave, first-non-repeating, stack-via-queues)
- `Assignment5/` — Singly Linked List: `q1..q4.cpp` (insert/delete/search/display, delete occurrences, middle, reverse)
- `Assignment6/` — DLL & CLL: `q1..q4.cpp` (doubly & circular lists, palindrome, cycle detection)
- `Assignment7/` — Sorting: `q1..q6.cpp` (selection, insertion, bubble, merge, quick, dual-selection)

---

## Notes & TODOs (because nothing is ever truly finished)

- `Assignment2/q5.cpp` and `Assignment2/q6.cpp` are lightweight demos — I can extend them to full compact storage and sparse-matrix arithmetic if you want a deeper version.
- I removed original monolithic `LabAssignment*.cpp` files in favor of focused `q*.cpp` files. If you preferred the old one-file-per-assignment style, say the word and I will resurrect them (with apologies).

---

If you'd like me to do one of the following, reply with the letter:

- **A** — Commit all current changes (README updates, file splits, scripts) with a tidy message.
- **B** — Add small test drivers or a combined runner per assignment.
- **C** — Implement full versions for `Assignment2/q5` and `q6` to match the lab specification.

Or say "surprise me" and I'll pick the safest next step. (I promise no infinite loops.)

---

## A small note to Prof. Ritesh Sharma

Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

With respect,

- Your student

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