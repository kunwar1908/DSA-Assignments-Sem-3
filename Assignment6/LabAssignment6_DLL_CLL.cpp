#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// =================================================================
// DOUBLY LINKED LIST (DLL) IMPLEMENTATION
// =================================================================

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DLLNode* head;
    DLLNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {
        DLLNode* current = head;
        DLLNode* next_node = nullptr;
        while (current != nullptr) {
            next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    // Utility: Check if list is empty
    bool isEmpty() const { return head == nullptr; }

    // Utility: Display (Forward)
    void display() const {
        if (isEmpty()) {
            cout << "DLL is empty." << endl;
            return;
        }
        cout << "DLL (Head <-> Tail): ";
        DLLNode* current = head;
        while (current != nullptr) {
            cout << current->data << (current->next != nullptr ? " <-> " : "");
            current = current->next;
        }
        cout << endl;
    }

    // 1(a) Insertion Anywhere (First, Last, Before/After Specific)
    void insert(int newVal, int targetVal = -1, bool after = true) {
        DLLNode* newNode = new DLLNode(newVal);

        // Case 1: Empty list (Always insert as head/tail)
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Case 2: Insert as first node (targetVal = -1 and no target node specified)
        if (targetVal == -1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Case 3: Find target node
        DLLNode* current = head;
        while (current != nullptr && current->data != targetVal) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Target node " << targetVal << " not found. Inserting at end." << endl;
            // Insert at the end if target is not found
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }

        // Case 4: Insert After
        if (after) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode; // Inserted at the end
            }
            current->next = newNode;
            cout << "Inserted " << newVal << " after " << targetVal << endl;

        } 
        // Case 5: Insert Before
        else { 
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            } else {
                head = newNode; // Inserted at the beginning
            }
            current->prev = newNode;
            cout << "Inserted " << newVal << " before " << targetVal << endl;
        }
    }
    
    // 1(b) Deletion of a specific node by value
    void deleteSpecific(int targetVal) {
        if (isEmpty()) {
            cout << "DLL is empty. Deletion failed." << endl;
            return;
        }
        DLLNode* current = head;
        while (current != nullptr && current->data != targetVal) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << targetVal << " not found." << endl;
            return;
        }

        // Adjust previous node's 'next' pointer
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next; // Target was head
        }

        // Adjust next node's 'prev' pointer
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; // Target was tail
        }
        
        cout << "Deleted node: " << current->data << "." << endl;
        delete current;
    }
    
    // 1(c) Search for a node
    bool searchNode(int targetVal) const {
        DLLNode* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == targetVal) {
                cout << "DLL Node " << targetVal << " found at position: " << position << "." << endl;
                return true;
            }
            current = current->next;
            position++;
        }
        cout << "DLL Node " << targetVal << " not found." << endl;
        return false;
    }
    
    // 3(i) Find size of Doubly Linked List
    int getSize() const {
        int count = 0;
        DLLNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Utility: Return head for palindrome check
    DLLNode* getHead() const { return head; }
    DLLNode* getTail() const { return tail; }
};

// =================================================================
// CIRCULAR LINKED LIST (CLL) IMPLEMENTATION
// =================================================================

struct CLLNode {
    int data;
    CLLNode* next;

    CLLNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    CLLNode* head; // Points to the first node

public:
    CircularLinkedList() : head(nullptr) {}
    // Simplified destructor for demo (proper cleanup is more complex in a CLL)
    ~CircularLinkedList() {
        if (head == nullptr) return;
        CLLNode* current = head->next;
        while (current != head) {
            CLLNode* next_node = current->next;
            delete current;
            current = next_node;
        }
        delete head;
    }

    // Utility: Check if list is empty
    bool isEmpty() const { return head == nullptr; }

    // 1(a) Insertion Anywhere (Simplified for menu demo: at front or end)
    void insertAtEnd(int newVal) {
        CLLNode* newNode = new CLLNode(newVal);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head; // Point back to self
            cout << "Inserted " << newVal << " as first node." << endl;
            return;
        }

        // Find the last node (the one pointing to head)
        CLLNode* current = head;
        while (current->next != head) {
            current = current->next;
        }
        // current is now the tail
        current->next = newNode;
        newNode->next = head;
        cout << "Inserted " << newVal << " at the end." << endl;
    }
    
    // 1(b) Deletion of a specific node by value
    void deleteSpecific(int targetVal) {
        if (isEmpty()) {
            cout << "CLL is empty. Deletion failed." << endl;
            return;
        }

        CLLNode* current = head;
        CLLNode* prev = nullptr;
        
        do {
            if (current->data == targetVal) {
                // Case 1: Target is the only node
                if (current == head && prev == nullptr) {
                    delete head;
                    head = nullptr;
                    cout << "Deleted the only node: " << targetVal << endl;
                    return;
                }
                
                // Case 2: Target is the head node (but not the only node)
                if (current == head) {
                    // Find the tail (prev node)
                    CLLNode* tail = head;
                    while (tail->next != head) tail = tail->next;
                    
                    head = head->next;
                    tail->next = head;
                    delete current;
                    cout << "Deleted head node: " << targetVal << endl;
                    return;
                }
                
                // Case 3: Target is in the middle or end
                prev->next = current->next;
                delete current;
                cout << "Deleted node: " << targetVal << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "CLL Node " << targetVal << " not found." << endl;
    }
    
    // 1(c) Search for a node
    bool searchNode(int targetVal) const {
        if (isEmpty()) return false;
        CLLNode* current = head;
        int position = 1;
        do {
            if (current->data == targetVal) {
                cout << "CLL Node " << targetVal << " found at position: " << position << "." << endl;
                return true;
            }
            current = current->next;
            position++;
        } while (current != head);
        cout << "CLL Node " << targetVal << " not found." << endl;
        return false;
    }

    // 2. Display all node values, repeating head at the end
    void displayWithHeadRepeat() const {
        if (isEmpty()) {
            cout << "CLL is empty." << endl;
            return;
        }
        cout << "CLL (Head -> ... -> Head): ";
        CLLNode* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        
        // Print head value one last time
        cout << head->data << "." << endl;
    }

    // 3(ii) Find size of Circular Linked List
    int getSize() const {
        if (isEmpty()) return 0;
        int count = 0;
        CLLNode* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);
        return count;
    }
    
    // Utility for Problem 5
    CLLNode* getHead() const { return head; }
};

// =================================================================
// PROBLEM 4: CHECK IF A DLL IS PALINDROME
// =================================================================
bool isPalindromeDLL(DLLNode* head, DLLNode* tail) {
    if (head == nullptr || head == tail) return true;

    // Use two pointers starting from head and tail
    DLLNode* forward = head;
    DLLNode* backward = tail;

    while (forward != backward && forward->prev != backward) {
        if (forward->data != backward->data) {
            return false;
        }
        forward = forward->next;
        backward = backward->prev;
    }
    return true;
}

void problem4_PalindromeDLL() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: PALINDROME DLL CHECK" << endl;
    cout << "======================================" << endl;

    // Example 1: LEVEL (Palindrome)
    DoublyLinkedList dll1;
    dll1.insert('L'); // Inserting characters as int (ASCII)
    dll1.insert('E');
    dll1.insert('V');
    dll1.insert('E');
    dll1.insert('L');
    
    cout << "List 1 (LEVEL): ";
    // Custom display for characters
    DLLNode* current = dll1.getHead();
    while (current != nullptr) {
        cout << (char)current->data << (current->next != nullptr ? " <-> " : "");
        current = current->next;
    }
    cout << endl;
    
    bool result1 = isPalindromeDLL(dll1.getHead(), dll1.getTail());
    cout << "Is Palindrome: " << (result1 ? "True" : "False") << endl;
    
    // Example 2: DATA (Not Palindrome)
    DoublyLinkedList dll2;
    dll2.insert('D');
    dll2.insert('A');
    dll2.insert('T');
    dll2.insert('A');

    cout << "\nList 2 (DATA): ";
    current = dll2.getHead();
    while (current != nullptr) {
        cout << (char)current->data << (current->next != nullptr ? " <-> " : "");
        current = current->next;
    }
    cout << endl;
    
    bool result2 = isPalindromeDLL(dll2.getHead(), dll2.getTail());
    cout << "Is Palindrome: " << (result2 ? "True" : "False") << endl;
}

// =================================================================
// PROBLEM 5: CHECK IF A LINKED LIST IS CIRCULAR (Tortoise and Hare)
// =================================================================

// Function to create a non-circular linked list for testing
CLLNode* createNonCircularList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    CLLNode* head = new CLLNode(values[0]);
    CLLNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new CLLNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to check if a list is circular using the Slow/Fast (Floyd's Cycle) algorithm
bool isCircular(CLLNode* head) {
    if (head == nullptr) return false;

    CLLNode* slow = head;
    CLLNode* fast = head->next; // Start fast one ahead

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true; // Cycle detected
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false; // Reached the end (NULL), so it's not circular
}

void problem5_CheckCircular() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 5: CHECK IF LIST IS CIRCULAR" << endl;
    cout << "======================================" << endl;

    // Example 1: Circular List (from Problem 2 demo)
    CircularLinkedList cll;
    cll.insertAtEnd(2);
    cll.insertAtEnd(4);
    cll.insertAtEnd(6);
    cll.insertAtEnd(7);
    cll.insertAtEnd(5);
    
    cout << "List 1 (Circular Demo): Output: " << (isCircular(cll.getHead()) ? "True" : "False") << endl;
    
    // Example 2: Non-Circular (Singly Linked List)
    vector<int> linear_vals = {10, 20, 30, 40};
    CLLNode* linear_head = createNonCircularList(linear_vals);

    cout << "List 2 (Linear): Output: " << (isCircular(linear_head) ? "True" : "False") << endl;

    // Clean up linear list
    CLLNode* current = linear_head;
    while (current != nullptr) {
        CLLNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    // Problem 1 & 3: Menu Driven and Size Check
    cout << "\n=================================================" << endl;
    cout << "  PROBLEM 1 & 3: DOUBLY LINKED LIST DEMO" << endl;
    cout << "=================================================" << endl;
    DoublyLinkedList dll;
    dll.insert(10); // Insert at beginning
    dll.insert(50); // Insert at end
    dll.insert(30, 10, true); // Insert 30 after 10
    dll.insert(20, 30, false); // Insert 20 before 30
    dll.display();
    cout << "Size (Q3i): " << dll.getSize() << endl;
    dll.searchNode(50);
    dll.deleteSpecific(10); // Delete head
    dll.deleteSpecific(50); // Delete tail
    dll.display();

    cout << "\n=================================================" << endl;
    cout << "  PROBLEM 1, 2, 3: CIRCULAR LINKED LIST DEMO" << endl;
    cout << "=================================================" << endl;
    CircularLinkedList cll;
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);
    
    // Problem 2: Display with head repeat
    cll.displayWithHeadRepeat();
    cout << "Size (Q3ii): " << cll.getSize() << endl;
    
    cll.deleteSpecific(40);
    cll.searchNode(80);
    cll.displayWithHeadRepeat();

    // Problem 4: Palindrome check on DLL
    problem4_PalindromeDLL();

    // Problem 5: Check Circularity
    problem5_CheckCircular();

    cout << "\nLab Assignment 6 Complete." << endl;
    return 0;
}