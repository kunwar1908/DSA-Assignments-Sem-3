#include <iostream>
#include <string>

using namespace std;

// Node structure for the Single Linked List
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// =================================================================
// SINGLY LINKED LIST CLASS IMPLEMENTATION (For Problem 1)
// =================================================================
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        Node* next_node = nullptr;
        while (current != nullptr) {
            next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
    }

    // (h) Display all the node values
    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Linked List: ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << (current->next != nullptr ? " -> " : "");
            current = current->next;
        }
        cout << endl;
    }

    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
    }

    // (b) Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        cout << "Inserted " << val << " at the end." << endl;
    }

    // (c) Insertion in between (before or after a node with specific value)
    void insertInBetween(int newVal, int targetVal, bool before) {
        if (head == nullptr) {
            cout << "List is empty. Insertion failed." << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != targetVal) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Target node " << targetVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newVal);

        if (before) {
            // Insert before targetVal
            if (prev == nullptr) { // Target is the head
                insertAtBeginning(newVal); // Reuse existing function
                delete newNode; // Avoid memory leak since insertAtBeginning created one
                return;
            }
            newNode->next = current;
            prev->next = newNode;
            cout << "Inserted " << newVal << " before " << targetVal << "." << endl;
        } else {
            // Insert after targetVal
            newNode->next = current->next;
            current->next = newNode;
            cout << "Inserted " << newVal << " after " << targetVal << "." << endl;
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted node: " << temp->data << " from the beginning." << endl;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted node: " << head->data << " from the end." << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        cout << "Deleted node: " << current->data << " from the end." << endl;
        delete current;
    }

    // (f) Deletion of a specific node by value
    void deleteSpecificNode(int targetVal) {
        if (head == nullptr) {
            cout << "List is empty. Deletion failed." << endl;
            return;
        }

        // Case 1: Target is the head node
        if (head->data == targetVal) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted head node: " << temp->data << "." << endl;
            delete temp;
            return;
        }

        // Case 2: Target is in the middle or end
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != targetVal) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << targetVal << " not found." << endl;
            return;
        }

        // Perform deletion
        prev->next = current->next;
        cout << "Deleted node: " << current->data << "." << endl;
        delete current;
    }

    // (g) Search for a node and display its position
    void searchNode(int targetVal) const {
        if (head == nullptr) {
            cout << "List is empty. Search failed." << endl;
            return;
        }
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == targetVal) {
                cout << "Node " << targetVal << " found at position: " << position << " (from head)." << endl;
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Node " << targetVal << " not found in the list." << endl;
    }
    
    // Getter for head (used by other problem functions)
    Node* getHead() const {
        return head;
    }

    // Setter for head (used by the reverse function)
    void setHead(Node* newHead) {
        head = newHead;
    }
};

void problem1_MenuDrivenSLL(SinglyLinkedList& list) {
    int choice, val, target, pos_choice;

    do {
        cout << "\n======================================" << endl;
        cout << "  PROBLEM 1: SINGLY LINKED LIST MENU" << endl;
        cout << "======================================" << endl;
        cout << " (a) 1. Insert at Beginning" << endl;
        cout << " (b) 2. Insert at End" << endl;
        cout << " (c) 3. Insert in Between" << endl;
        cout << " (d) 4. Delete from Beginning" << endl;
        cout << " (e) 5. Delete from End" << endl;
        cout << " (f) 6. Delete Specific Node (by value)" << endl;
        cout << " (g) 7. Search for Node" << endl;
        cout << " (h) 8. Display List" << endl;
        cout << " 9. Exit Problem 1" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: cout << "Value to insert: "; if (cin >> val) list.insertAtBeginning(val); break;
            case 2: cout << "Value to insert: "; if (cin >> val) list.insertAtEnd(val); break;
            case 3: 
                cout << "New value: "; if (!(cin >> val)) break;
                cout << "Target value: "; if (!(cin >> target)) break;
                cout << "Insert (1:Before / 2:After): "; if (!(cin >> pos_choice)) break;
                list.insertInBetween(val, target, pos_choice == 1); 
                break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: cout << "Value to delete: "; if (cin >> val) list.deleteSpecificNode(val); break;
            case 7: cout << "Value to search: "; if (cin >> val) list.searchNode(val); break;
            case 8: list.display(); break;
            case 9: cout << "Exiting Problem 1." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 9);
}


// =================================================================
// PROBLEM 2: COUNT AND DELETE ALL OCCURRENCES OF A KEY
// =================================================================
int countAndDelete(Node*& head, int key) {
    int count = 0;

    // Handle initial nodes that match the key (new head pointer required)
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Handle nodes in the middle and end
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data == key) {
            // Delete the current node
            prev->next = current->next;
            Node* temp = current;
            current = current->next; // Advance current before deleting temp
            delete temp;
            count++;
        } else {
            // Move pointers forward
            prev = current;
            current = current->next;
        }
    }

    return count;
}

void problem2_CountAndDeleteOccurrences() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: COUNT AND DELETE KEY" << endl;
    cout << "======================================" << endl;

    // Input: 1->2->1->2->1->3->1, key: 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);
    int key = 1;
    
    // Display original list
    SinglyLinkedList list;
    list.setHead(head);
    cout << "Original List: "; list.display();

    int count = countAndDelete(head, key);
    
    list.setHead(head); // Update list object's head

    cout << "Count of key " << key << ": " << count << endl;
    cout << "Updated List: "; list.display(); 
    // Expected: 2->2->3.
}

// =================================================================
// PROBLEM 3: FIND THE MIDDLE OF A LINKED LIST (Slow/Fast Pointers)
// =================================================================
int findMiddle(Node* head) {
    if (head == nullptr) return -1; // Empty list

    Node* slow = head;
    Node* fast = head;

    // Fast pointer moves two steps, slow pointer moves one step.
    // When fast reaches the end, slow is at the middle.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

void problem3_FindMiddle() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 3: FIND MIDDLE NODE" << endl;
    cout << "======================================" << endl;

    // Input 1: Odd length 1->2->3->4->5. Middle: 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    
    SinglyLinkedList list1;
    list1.setHead(head1);
    cout << "List 1 (Odd Length): "; list1.display();
    cout << "Middle Node: " << findMiddle(head1) << endl;

    // Input 2: Even length 1->2->3->4. Middle: 3 (second middle node)
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);
    head2->next->next->next = new Node(40);
    
    SinglyLinkedList list2;
    list2.setHead(head2);
    cout << "List 2 (Even Length): "; list2.display();
    cout << "Middle Node: " << findMiddle(head2) << endl; 
    // Note: The slow-fast approach finds the second of the two middle nodes for even lists.
}


// =================================================================
// PROBLEM 4: REVERSE A LINKED LIST
// =================================================================
Node* reverseList(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next_node = nullptr;

    while (current != nullptr) {
        // 1. Store next node
        next_node = current->next;
        // 2. Reverse current node's pointer (make it point to prev)
        current->next = prev;
        // 3. Move prev and current one step forward
        prev = current;
        current = next_node;
    }
    
    // Prev is the new head of the reversed list
    return prev;
}

void problem4_ReverseList() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: REVERSE LINKED LIST" << endl;
    cout << "======================================" << endl;
    
    // Input: 1->2->3->4->NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    SinglyLinkedList list;
    list.setHead(head);
    cout << "Original List: "; list.display();

    Node* new_head = reverseList(head);
    list.setHead(new_head);
    
    cout << "Reversed List: "; list.display();
    // Expected: 4->3->2->1->NULL
}


// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    SinglyLinkedList list;

    // Problem 1 is interactive
    problem1_MenuDrivenSLL(list);

    // Problems 2, 3, and 4 run automated demos on separate lists
    problem2_CountAndDeleteOccurrences();
    problem3_FindMiddle();
    problem4_ReverseList();

    // The destructor will clean up memory for the lists created here (list, list1, list2) 
    // and the manual cleanup in problem 2 and 4.

    cout << "\nLab Assignment 5 Complete." << endl;
    return 0;
}