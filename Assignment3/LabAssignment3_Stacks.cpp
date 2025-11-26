#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

// Maximum size of the stack
const int MAX_SIZE = 50;

// =================================================================
// STACK CLASS IMPLEMENTATION (For Problem 1)
// =================================================================
class ArrayStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    // (iii) Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // (iv) Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // (i) Push operation
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << data << "." << endl;
            return;
        }
        arr[++top] = data;
        cout << data << " pushed to stack." << endl;
    }

    // (ii) Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1; // Sentinel value for failure
        }
        return arr[top--];
    }

    // (vi) Peek operation (return top element without removing)
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. Peek failed." << endl;
            return -1; // Sentinel value
        }
        return arr[top];
    }

    // (v) Display operation
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top -> Bottom): [";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << (i == 0 ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

void problem1_MenuDrivenStack() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 1: MENU DRIVEN STACK" << endl;
    cout << "======================================" << endl;

    ArrayStack stack;
    int choice;
    int value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit Problem 1" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                if (cin >> value) stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) cout << "Popped value: " << value << endl;
                break;
            case 3:
                value = stack.peek();
                if (value != -1) cout << "Top value (Peek): " << value << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Is Empty: " << (stack.isEmpty() ? "True" : "False") << endl;
                break;
            case 6:
                cout << "Is Full: " << (stack.isFull() ? "True" : "False") << endl;
                break;
            case 7:
                cout << "Exiting Problem 1." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 7);
}


// =================================================================
// PROBLEM 2: REVERSE A STRING USING STACK
// =================================================================
string reverseString(const string& str) {
    if (str.empty()) return "";
    
    // Use std::string as a stack (LIFO)
    string char_stack;
    
    // Push characters onto the stack
    for (char c : str) {
        char_stack.push_back(c);
    }

    string reversed_str = "";
    
    // Pop characters from the stack to get the reversed string
    while (!char_stack.empty()) {
        reversed_str.push_back(char_stack.back());
        char_stack.pop_back();
    }
    
    return reversed_str;
}

void problem2_ReverseString() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: REVERSE STRING USING STACK" << endl;
    cout << "======================================" << endl;
    
    string input = "DataStructure";
    string reversed = reverseString(input);
    
    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reversed << endl;
}


// =================================================================
// PROBLEM 3: CHECK BALANCED PARENTHESES
// =================================================================
bool areParenthesesBalanced(const string& expr) {
    string s; // Use string as a stack for characters

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push_back(c); // Push opening bracket
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false; // Closing bracket without an opening one
            }
            char top_char = s.back();
            s.pop_back();

            if ((c == ')' && top_char != '(') ||
                (c == '}' && top_char != '{') ||
                (c == ']' && top_char != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    // Expression is balanced only if the stack is empty at the end
    return s.empty();
}

void problem3_BalancedParentheses() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 3: BALANCED PARENTHESES" << endl;
    cout << "======================================" << endl;
    
    string expr1 = "{([])}";
    string expr2 = "([)]";
    
    cout << "Expression 1: " << expr1 << " -> " << (areParenthesesBalanced(expr1) ? "BALANCED" : "NOT BALANCED") << endl;
    cout << "Expression 2: " << expr2 << " -> " << (areParenthesesBalanced(expr2) ? "NOT BALANCED" : "BALANCED") << endl;
}


// =================================================================
// PROBLEM 4: INFIX TO POSTFIX CONVERSION
// =================================================================

// Utility function to get precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0; // For parentheses and others
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    string op_stack; // Stack for operators

    for (char token : infix) {
        if (isalnum(token)) {
            // Operand: add to the output string
            postfix += token;
        } else if (token == '(') {
            // Opening parenthesis: push to stack
            op_stack.push_back(token);
        } else if (token == ')') {
            // Closing parenthesis: pop and append operators until '(' is found
            while (!op_stack.empty() && op_stack.back() != '(') {
                postfix += op_stack.back();
                op_stack.pop_back();
            }
            if (!op_stack.empty() && op_stack.back() == '(') {
                op_stack.pop_back(); // Pop the opening parenthesis
            }
        } else {
            // Operator: pop and append operators with higher or equal precedence
            while (!op_stack.empty() && precedence(op_stack.back()) >= precedence(token)) {
                postfix += op_stack.back();
                op_stack.pop_back();
            }
            op_stack.push_back(token); // Push the current operator
        }
    }

    // Pop all remaining operators from the stack
    while (!op_stack.empty()) {
        postfix += op_stack.back();
        op_stack.pop_back();
    }
    
    return postfix;
}

void problem4_InfixToPostfix() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: INFIX TO POSTFIX" << endl;
    cout << "======================================" << endl;

    string infix = "a+b*(c-d)/e";
    string postfix = infixToPostfix(infix);
    
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl; 
    // Expected: abcd-*e/+
}


// =================================================================
// PROBLEM 5: POSTFIX EXPRESSION EVALUATION
// =================================================================

// Utility function to perform arithmetic
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero!");
            return a / b;
    }
    return 0;
}

int evaluatePostfix(const string& postfix) {
    string val_stack; // Stack for operands (values)
    
    for (char token : postfix) {
        if (isdigit(token)) {
            // Operand: Convert char to int and push to stack
            val_stack.push_back(token - '0'); 
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            // Operator: Pop two operands, perform operation, push result
            if (val_stack.size() < 2) {
                throw runtime_error("Invalid Postfix Expression: Missing operand.");
            }
            int val2 = val_stack.back(); val_stack.pop_back();
            int val1 = val_stack.back(); val_stack.pop_back();
            
            int result = applyOp(val1, val2, token);
            val_stack.push_back(result);
        }
    }
    
    if (val_stack.size() == 1) {
        return val_stack.back();
    } else {
        throw runtime_error("Invalid Postfix Expression: Too many operands.");
    }
}

void problem5_EvaluatePostfix() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 5: EVALUATE POSTFIX" << endl;
    cout << "======================================" << endl;

    // Postfix: 2 3 1 * + 9 -
    // Evaluation steps:
    // 1. (2)
    // 2. (2, 3)
    // 3. (2, 3, 1)
    // 4. (2, 3*1=3) -> (2, 3)
    // 5. (2+3=5) -> (5)
    // 6. (5, 9)
    // 7. (5-9=-4) -> (-4)
    string postfix = "231*+9-"; 
    
    try {
        int result = evaluatePostfix(postfix);
        cout << "Postfix Expression: " << postfix << " (Assuming single-digit integers)" << endl;
        cout << "Evaluation Result: " << result << endl; 
    } catch (const exception& e) {
        cerr << "Error evaluating postfix: " << e.what() << endl;
    }
}


// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    // Note: The menu driven program (Problem 1) will run first and require user interaction.
    problem1_MenuDrivenStack();

    // The rest of the problems run automatically after the menu exits
    problem2_ReverseString();
    problem3_BalancedParentheses();
    problem4_InfixToPostfix();
    problem5_EvaluatePostfix();

    cout << "\nLab Assignment 3 Complete." << endl;
    return 0;
}