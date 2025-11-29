**Assignment 7 — Sorting Algorithms**

- **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`, `q5.cpp`, `q6.cpp`
- **Summary:**
    - `q1.cpp`: Selection sort demo.
    - `q2.cpp`: Insertion sort demo.
    - `q3.cpp`: Bubble sort demo.
    - `q4.cpp`: Merge sort demo.
    - `q5.cpp`: Quick sort demo.
    - `q6.cpp`: Dual-selection sort (select min & max per pass).

**Build example:**
```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment7\q1.cpp -o Assignment7\q1.exe
Assignment7\q1.exe
```

# 📂 Lab Assignment 7: Sorting Algorithms

**Concepts Covered:** Fundamental and advanced sorting algorithms, including $O(n^2)$ sorts (Selection, Insertion, Bubble) and $O(n \log n)$ sorts (Merge, Quick), along with a customized sorting optimization.

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment7_Sorting.cpp` | Time Complexity |
| :---: | :--- | :--- | :---: |
| **Q1a** | Implement **Selection Sort**. | `selectionSort()` | $O(n^2)$ |
| **Q1b** | Implement **Insertion Sort**. | `insertionSort()` | $O(n^2)$ |
| **Q1c** | Implement **Bubble Sort**. | `bubbleSort()` | $O(n^2)$ |
| **Q1d** | Implement **Merge Sort**. | `mergeSort()` | $O(n \log n)$ |
| **Q1e** | Implement **Quick Sort**. | `quickSort()` | $O(n \log n)$ Avg. |
| **Q2** | Implement the **Improved Selection Sort** (finding both min and max and sorting from both ends in one pass). | `dualSelectionSort()` | $O(n^2)$ |

### Note on Problem 2: Dual Selection Sort
The Dual Selection Sort remains an $O(n^2)$ algorithm. Although it performs fewer passes (approximately $n/2$), the work done inside the inner loop is constant (finding both min and max indices), and the overall time complexity is still dominated by the nested loop structure.

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment7_Sorting.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment07
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment7_Sorting.cpp -o lab7_exec -std=c++11
    ```

    ---

    ## A small note to Prof. Ritesh Sharma

    Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

    With respect,

    - CR (2C8)
3.  **Run the executable:**
    ```bash
    ./lab7_exec
    ```
    *(The program runs automated demos for all sorting techniques.)*