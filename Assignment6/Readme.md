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
3.  **Run the executable:**
    ```bash
    ./lab6_exec
    ```
    *(Note: The program runs a sequence of automated demos for all problems.)*