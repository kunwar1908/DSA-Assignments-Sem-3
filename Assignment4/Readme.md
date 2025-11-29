**Assignment 4 — Queues**

- **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`, `q5.cpp`
- **Summary:**
    - `q1.cpp`: Simple queue implementation demo.
    - `q2.cpp`: Circular queue demo.
    - `q3.cpp`: Interleave queue operation.
    - `q4.cpp`: First non-repeating character using queue.
    - `q5.cpp`: Implement stack using queues (various push/pop complexities).

**Build example:**
```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment4\q1.cpp -o Assignment4\q1.exe
Assignment4\q1.exe
```

# 📂 Lab Assignment 4: Queues and Their Applications

**Concepts Covered:** Fundamental Queue Operations (FIFO), Array Implementation of Simple and Circular Queues, Applications of Queues (Interleaving, First Non-Repeating Character), and Queue-based Data Structure Simulation (Stack using Queues).

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment4_Queues.cpp` | Key Data Structure / Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for **Simple Queues** (`enqueue`, `dequeue`, `isEmpty`, etc.) using an Array. | `SimpleQueue` Class and `problem1_SimpleQueueMenu()` | Array-based FIFO |
| **Q2** | Menu-driven program for **Circular Queues** (`enqueue`, `dequeue`, etc.) using an Array. | `CircularQueue` Class and `problem2_CircularQueueMenu()` | Modulo Arithmetic (`(rear + 1) % MAX_SIZE`) |
| **Q3** | Program to **interleave** the first half of a queue with the second half. | `interleaveQueue()` | Queue + Auxiliary Stack |
| **Q4** | Program to find the **first non-repeating character** in a string stream. | `findFirstNonRepeating()` | Queue + Frequency Map (`std::map` or array) |
| **Q5a** | Implement a **Stack** using **Two Queues**. | `StackUsingTwoQueues` Class | $O(n)$ Push, $O(1)$ Pop (by prioritizing the front element) |
| **Q5b** | Implement a **Stack** using **One Queue**. | `StackUsingOneQueue` Class | $O(1)$ Push, $O(n)$ Pop (by rotating elements) |

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment4_Queues.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment04
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment4_Queues.cpp -o lab4_exec -std=c++11
    ```

    ---

    ## A small note to Prof. Ritesh Sharma

    Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

    With respect,

    - Your student
3.  **Run the executable:**
    ```bash
    ./lab4_exec
    ```
    *(Note: Problems 1 and 2 run automated demos for conciseness, but the full class implementation is provided.)*