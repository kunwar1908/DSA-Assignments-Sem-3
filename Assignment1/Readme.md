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
        printf("%d", arr[i]);
    return 0;
}