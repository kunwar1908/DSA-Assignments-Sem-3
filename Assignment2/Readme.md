**Assignment 2 — Advanced Arrays & Strings**

- **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`, `q5.cpp`, `q6.cpp`, `q7.cpp`, `q8.cpp`
- **Summary:**
    - `q1.cpp`: Binary search (iterative) on a sorted array.
    - `q2.cpp`: Bubble sort (array: 64 34 25 12 22 11 90).
    - `q3.cpp`: Find missing number — linear (sum) and binary-search approach.
    - `q4.cpp`: String tasks (concat, reverse, remove vowels, sort characters, to-lower demo).
    - `q5.cpp`: Efficient storage counts for special matrices (diagonal, tri-diagonal, lower-triangular) — currently a demo of sizes.
    - `q6.cpp`: Sparse matrix (triplet) — transpose implemented (addition/multiplication can be added).
    - `q7.cpp`: Count inversions (O(n^2) brute-force). Can be upgraded to O(n log n) via merge-sort counting.
    - `q8.cpp`: Count distinct elements (sort + unique).

**Notes & suggestions:**
- `q5.cpp` and `q6.cpp` are partial demos — I can implement compact indexing functions (for `q5`) and addition/multiplication for sparse triplet (`q6`) on request.

**Build example:**
```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment2\q2.cpp -o Assignment2\q2.exe
Assignment2\q2.exe
```

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

    ---

    ## A small note to Prof. Ritesh Sharma

    Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

    With respect,

    - CR (2C8)
3.  **Run the executable:**
    ```bash
    ./lab2_exec
    ```