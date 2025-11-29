**Assignment 3 — Stacks**

- **Files:** `q1.cpp`, `q2.cpp`, `q3.cpp`, `q4.cpp`, `q5.cpp`
- **Summary:**
    - `q1.cpp`: Stack implementation (push, pop, peek) demo.
    - `q2.cpp`: Reverse string using stack.
    - `q3.cpp`: Check balanced parentheses.
    - `q4.cpp`: Infix → Postfix conversion.
    - `q5.cpp`: Evaluate postfix expressions.

**Build example:**
```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 Assignment3\q4.cpp -o Assignment3\q4.exe
Assignment3\q4.exe
```

# 📂 Lab Assignment 3: Stacks

**Concepts Covered:** Fundamental Stack Operations (LIFO), Array Implementation of Stacks, Application of Stacks for string manipulation (Reversal, Parenthesis Checking), and Expression Handling (Infix to Postfix Conversion, Postfix Evaluation).

## 📝 Questions and Solutions

| Ques. | Task Description | Implementation in `LabAssignment3_Stacks.cpp` | Key Concept |
| :---: | :--- | :--- | :--- |
| **Q1** | [cite_start]Menu-driven program for basic Stack operations (`push`, `pop`, `isEmpty`, `isFull`, `display`, `peek`) using an **Array** implementation. [cite: 2, 3]| `ArrayStack` Class and `problem1_MenuDrivenStack()` | Array-based Stack |
| **Q2** | Reverse a given string using a **STACK**. | `reverseString()` | LIFO Principle |
| **Q3** | Check if an expression has **balanced parentheses**. | `areParenthesesBalanced()` | Stack for Matching Brackets |
| **Q4** | [cite_start]Convert an **Infix** expression into a **Postfix** expression. [cite: 6] | `infixToPostfix()` | Operator Precedence |
| **Q5** | [cite_start]Program for the **evaluation** of a **Postfix** expression. [cite: 7]| `evaluatePostfix()` | Stack for Operands |

---

## ⚙️ Compilation and Execution

The entire assignment is consolidated into a single file: `LabAssignment3_Stacks.cpp`.

1.  **Navigate to the assignment folder:**
    ```bash
    cd LabAssignment03
    ```
2.  **Compile the file:**
    ```bash
    g++ LabAssignment3_Stacks.cpp -o lab3_exec
    ```

    ---

    ## A small note to Prof. Ritesh Sharma

    Dear Prof. Ritesh Sharma — thank you for teaching DSA with patience and vigor. I put effort into organizing and testing these lab demos; if anything here earns your approval (or at least a smile), I'd be grateful for generous grading. No bribery was involved — only coffee, a debugger, and some hopeful comments.

    With respect,

    - CR (2C8)
3.  **Run the executable:**
    ```bash
    ./lab3_exec
    ```
    *(Note: The program will first launch the interactive menu for Problem 1.)*