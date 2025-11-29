# UCS301 Data Structures: Lab Assignment 1 (Arrays)

This repository contains the C++ solution for Lab Assignment 1, focusing on fundamental array and 2D array (matrix) operations.

## File Structure

* `LabAssignment1_Arrays.cpp`: The complete C++ source code file.

## Requirements

* A C++ compiler (e.g., GCC, g++).
* Standard C++ libraries (`iostream`, `algorithm`, `vector`).

## How to Compile and Run

1.  **Clone the repository:**
    ```bash
    git clone [your-repo-link]
    cd [your-repo-name]
    ```

2.  **Compile the C++ code (using g++):**
    ```bash
    g++ LabAssignment1_Arrays.cpp -o array_lab
    ```

3.  **Run the executable:**
    ```bash
    ./array_lab
    ```

## Assignment Tasks Implemented

### 1. Menu Driven Program
A primary menu to demonstrate the following dynamic operations on a 1D array:
* `CREATE`
* `DISPLAY`
* `INSERT` (at a specific position)
* `DELETE` (from a specific position)
* `LINEAR SEARCH`

### 2. Remove Duplicate Elements
Logic to remove all duplicate elements from an array, leaving only unique values.

### 3. Predict the Output
Analysis of the provided C code snippet:
```c
int main() {
    int arr[5] = {1};
    for (int i = 0; i < 5; i++)
        **Assignment 1 — Arrays**

        - **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`, `q5.cpp`
        - **Summary:**
          - `q1.cpp`: Menu-driven array operations (create, display, insert, delete, linear search).
          - `q2.cpp`: Remove duplicates and list unique elements.
          - `q3.cpp`: Predict-the-output / code analysis demo.
          - `q4.cpp`: Array and matrix utilities (reverse array, matrix multiplication/transpose demo).
          - `q5.cpp`: Row/column sums for a matrix demo.

        **How to build (example):**
        ```powershell
        & 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment1\q1.cpp -o Assignment1\q1.exe
        Assignment1\q1.exe
        ```

        If you want the original monolithic file kept instead of the split files, let me know.

        ---

        ## A small note to Prof. Ritesh Sharma

        Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

        With respect,

        - Your student