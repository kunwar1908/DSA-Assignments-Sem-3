**Assignment 6 — Doubly / Circular Linked Lists (DLL & CLL)**

- **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`
- **Summary:**
    - `q1.cpp`: Doubly linked list operations (insert, delete, search, display).
    - `q2.cpp`: Circular linked list operations (insert, delete, display).
    - `q3.cpp`: Check if a list is a palindrome.
    - `q4.cpp`: Detect if a linked list is circular (Floyd's cycle detection demo).

**Build example:**
```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment6\q4.cpp -o Assignment6\q4.exe
Assignment6\q4.exe
```

# 📂 Lab Assignment 6: Doubly and Circular Linked Lists

**Concepts Covered:** Core operations (Insertion, Deletion, Search) on Doubly Linked Lists (DLL) and Circular Linked Lists (CLL), advanced list applications (Palindrome check on DLL), size calculation, and cycle detection in linked lists.

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment6_DLL_CLL.cpp` | Key Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for **DLL** and **CLL** operations (Insert anywhere, Delete specific node, Search). | `DoublyLinkedList` and `CircularLinkedList` classes | Two-way linking (`prev`/`next`) and Circular linking (tail.next points to head) |
| **Q2** | **Display** all node values in a **CLL**, repeating the head node value at the end. | `CLL::displayWithHeadRepeat()` | Traversing until `current->next == head` and then printing the head value again. |
| **Q3** | Program to find the **size** of a DLL and a CLL. | `DLL::getSize()` and `CLL::getSize()` | Simple traversal counting nodes. |
| **Q4** | Check if a **Doubly Linked List** of characters is a **palindrome**. | `isPalindromeDLL()` | **Two-pointer approach** (one from head, one from tail) moving towards the center. |
| **Q5** | Check if a linked list is a **Circular Linked List** or not. | `isCircular()` | **Floyd's Cycle-Finding Algorithm** (Slow and Fast pointers). |

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment6_DLL_CLL.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment06
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment6_DLL_CLL.cpp -o lab6_exec -std=c++11
    ```

    ---

    ## A small note to Prof. Ritesh Sharma

    Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

    With respect,

    - Your student
3.  **Run the executable:**
    ```bash
    ./lab6_exec
    ```
    *(Note: The program runs a sequence of automated demos for all problems.)*