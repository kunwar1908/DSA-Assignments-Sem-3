# 📂 Lab Assignment 2: Advanced Arrays, Searching, and Sorting

**Concepts Covered:** Binary Search, Bubble Sort, Time Complexity ($O(\log n)$), Missing Numbers, String Manipulation, Space Optimization for Special Matrices (Diagonal, Triangular, Symmetric), Sparse Matrices, and Inversion Counting.

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment2_AdvancedArrays.cpp` | Time Complexity |
| :---: | :--- | :--- | :---: |
| **Q1** | Implement **Binary Search** algorithm. | `problem1_BinarySearch()` | $O(\log n)$ |
| **Q2** | Code the **Bubble Sort** algorithm. | `problem2_BubbleSort()` | $O(n^2)$ |
| **Q3** | Find a **Missing Number** in a sorted array (range 1 to $n$). | `findMissingLinear()` | $O(n)$ |
| | | `findMissingBinary()` | $O(\log n)$ |
| **Q4** | String Programs (Concatenate, Reverse, Delete Vowels, Sort, Case Convert). | `problem4_Strings()` | Varies (Mostly $O(n)$) |
| **Q5** | Implement **efficient space storage** logic for special matrices (Diagonal, Tri-diagonal, Triangular, Symmetric). | `problem5_EfficientStorage()` (Conceptual explanation/formulas) | $O(1)$ (Space analysis) |
| **Q6** | Implement Sparse Matrix operations (Transpose, Addition, Multiplication) using **Triplet** representation. | `transposeSparseMatrix()` (Transpose implemented) | $O(T)$ (Simple Transpose) |
| **Q7** | Write a program to count the number of **Inversions** in an array. | `countInversions()` | $O(n^2)$ |
| **Q8** | Write a program to count the total number of **distinct elements** in an array. | `countDistinctElements()` | $O(n \log n)$ (Due to sorting) |

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment2_AdvancedArrays.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment02
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment2_AdvancedArrays.cpp -o lab2_exec
    ```
3.  **Run the executable:**
    ```bash
    ./lab2_exec
    ```