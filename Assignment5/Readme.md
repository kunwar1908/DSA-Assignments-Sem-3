# 📂 Lab Assignment 5: Singly Linked Lists (SLL)

**Concepts Covered:** Core operations on a Singly Linked List (SLL), including various forms of insertion and deletion, traversal, and advanced SLL applications (counting/deleting occurrences, finding the middle node, and list reversal).

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment5_SinglyLinkedList.cpp` | Key Technique |
| :---: | :--- | :--- | :--- |
| **Q1** | Menu-driven program for SLL operations: Insertion (Begin, End, Between), Deletion (Begin, End, Specific Node), Search, and Display. | `SinglyLinkedList` Class and `problem1_MenuDrivenSLL()` | Head/Tail pointer manipulation |
| **Q2** | Count occurrences of a key and **delete all** instances. | `countAndDelete()` | Handling head node deletion and robust pointer adjustment (`prev`, `current`) |
| **Q3** | Program to find the **middle node** of a linked list. | `findMiddle()` | **Slow and Fast Pointer** technique (Tortoise and Hare) |
| **Q4** | Program to **reverse** a linked list. | `reverseList()` | Iterative reversal using three pointers: `prev`, `current`, and `next_node` |

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment5_SinglyLinkedList.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment05
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment5_SinglyLinkedList.cpp -o lab5_exec -std=c++11
    ```
3.  **Run the executable:**
    ```bash
    ./lab5_exec
    ```
    *(Note: The program starts with the interactive menu for Problem 1, followed by automated demos for Problems 2, 3, and 4.)*
    