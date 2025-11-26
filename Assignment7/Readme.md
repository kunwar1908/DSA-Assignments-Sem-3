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
3.  **Run the executable:**
    ```bash
    ./lab7_exec
    ```
    *(The program runs automated demos for all sorting techniques.)*