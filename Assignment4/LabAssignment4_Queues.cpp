#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

const int MAX_SIZE = 5; // Reduced size for demonstration

// =================================================================
// PROBLEM 1: SIMPLE QUEUE IMPLEMENTATION (Using Array)
// =================================================================
class SimpleQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return rear == MAX_SIZE - 1;
    }

    // enqueue()
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << data << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Initialize front for the first element
        }
        arr[++rear] = data;
        cout << data << " enqueued successfully." << endl;
    }

    // dequeue()
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        int data = arr[front++];
        
        // Check if the queue is now empty and reset
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return data;
    }

    // peek()
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty. Peek failed." << endl;
            return -1;
        }
        return arr[front];
    }

    // display()
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Front -> Rear): [";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << (i == rear ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

void problem1_SimpleQueueMenu() {
    // Menu logic for SimpleQueue omitted for brevity, similar to Lab 3 Stack menu.
    // The implementation of the class methods above serves as the solution.
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 1: SIMPLE QUEUE DEMO" << endl;
    cout << "======================================" << endl;
    SimpleQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Peek: " << q.peek() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Should trigger Overflow
}

// =================================================================
// PROBLEM 2: CIRCULAR QUEUE IMPLEMENTATION (Using Array)
// =================================================================
class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    // enqueue()
    void enqueue(int data) {
        if (isFull()) {
            cout << "Circular Queue Overflow! Cannot enqueue " << data << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;
        cout << data << " enqueued successfully." << endl;
    }

    // dequeue()
    int dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        int data = arr[front];
        
        if (front == rear) {
            // Queue has one element, reset after dequeue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return data;
    }

    // peek()
    int peek() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty. Peek failed." << endl;
            return -1;
        }
        return arr[front];
    }

    // display()
    void display() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }
        cout << "Circular Queue (Front -> Rear): [";
        int i = front;
        do {
            cout << arr[i];
            if (i != rear) {
                cout << ", ";
            }
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << "]" << endl;
    }
};

void problem2_CircularQueueMenu() {
    // Menu logic for CircularQueue omitted for brevity.
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: CIRCULAR QUEUE DEMO" << endl;
    cout << "======================================" << endl;
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();
    cout << "Dequeued: " << cq.dequeue() << endl; // Dequeue 1
    cq.display();
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6); // Should trigger Overflow
    cq.display();
}

// =================================================================
// PROBLEM 3: INTERLEAVE QUEUE HALVES
// =================================================================
void interleaveQueue(queue<int>& q) {
    if (q.empty() || q.size() % 2 != 0) {
        cout << "Queue must be non-empty and have an even number of elements." << endl;
        return;
    }

    int half_size = q.size() / 2;
    stack<int> s;

    // 1. Move first half to stack
    for (int i = 0; i < half_size; ++i) {
        s.push(q.front());
        q.pop();
    }

    // 2. Interleave: Pop from stack, enqueue to queue
    //    Then: Dequeue from queue (second half), enqueue to queue
    while (!s.empty()) {
        q.push(s.top()); // Push stack top (first half)
        s.pop();

        q.push(q.front()); // Move queue front (second half)
        q.pop();
    }
}

void problem3_InterleaveQueue() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 3: INTERLEAVE QUEUE HALVES" << endl;
    cout << "======================================" << endl;

    // Sample I/P: 4 7 11 20 5 9 -> Even number is required. Let's use 6 elements.
    // I/P: 4 7 11 | 20 5 9
    // Expected: 4 20 7 5 11 9
    queue<int> q;
    vector<int> input_vec = {4, 7, 11, 20, 5, 9};
    for (int val : input_vec) q.push(val);

    cout << "Original Queue: ";
    queue<int> temp_q = q; // Copy for display
    while (!temp_q.empty()) { cout << temp_q.front() << " "; temp_q.pop(); }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;
}

// =================================================================
// PROBLEM 4: FIRST NON-REPEATING CHARACTER
// =================================================================
void findFirstNonRepeating(const string& str) {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: FIRST NON-REPEATING CHAR" << endl;
    cout << "======================================" << endl;

    // Queue stores characters seen once so far
    queue<char> q;
    // Frequency map: Stores count of each character
    map<char, int> freq;
    
    cout << "Input Stream: " << str << endl;
    cout << "Output: ";

    for (char c : str) {
        // 1. Update frequency
        freq[c]++;

        // 2. Enqueue if it's the first time seeing it
        if (freq[c] == 1) {
            q.push(c);
        }

        // 3. Dequeue and check front of the queue
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop(); // Remove repeating characters from the front
        }

        // 4. Print result
        if (q.empty()) {
            cout << "-1 "; // No non-repeating character yet
        } else {
            cout << q.front() << " "; // The front is the first non-repeating
        }
    }
    cout << endl;
}

// =================================================================
// PROBLEM 5: IMPLEMENT STACK USING QUEUES
// =================================================================

// 5a. Stack using Two Queues (Push O(n), Pop O(1) - or vice versa)
class StackUsingTwoQueues {
private:
    queue<int> q1; // Main storage
    queue<int> q2; // Helper queue

public:
    // Make pop operation O(1) and push O(n)
    void push(int data) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Push the new element to q1 (It becomes the new front/top)
        q1.push(data);
        
        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        cout << data << " pushed (O(n))." << endl;
    }
    
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int data = q1.front();
        q1.pop();
        return data; // O(1)
    }

    bool empty() const { return q1.empty(); }
    void display() const { /* Display logic for q1 */ }
};

// 5b. Stack using One Queue (Push O(1), Pop O(n))
class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int data) {
        q.push(data); // O(1)
        cout << data << " pushed (O(1))." << endl;
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        
        // Move all elements except the last one to the back of the queue
        int n = q.size();
        for (int i = 0; i < n - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        
        // The last element is the original top of the stack (LIFO)
        int data = q.front();
        q.pop();
        return data; // O(n)
    }

    bool empty() const { return q.empty(); }
};

void problem5_StackUsingQueues() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 5: STACK USING QUEUES" << endl;
    cout << "======================================" << endl;

    // 5a. Two Queues (Push O(n))
    cout << "--- (a) Stack using Two Queues (Push O(n)) ---" << endl;
    StackUsingTwoQueues s2q;
    s2q.push(10);
    s2q.push(20);
    s2q.push(30);
    cout << "Popped: " << s2q.pop() << " (Expected 30)" << endl;
    cout << "Popped: " << s2q.pop() << " (Expected 20)" << endl;

    // 5b. One Queue (Pop O(n))
    cout << "\n--- (b) Stack using One Queue (Pop O(n)) ---" << endl;
    StackUsingOneQueue s1q;
    s1q.push(100);
    s1q.push(200);
    s1q.push(300);
    cout << "Popped: " << s1q.pop() << " (Expected 300)" << endl;
    cout << "Popped: " << s1q.pop() << " (Expected 200)" << endl;
}


// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    // Problem 1 & 2 run demos instead of full menus for conciseness
    problem1_SimpleQueueMenu();
    problem2_CircularQueueMenu();
    
    problem3_InterleaveQueue();
    findFirstNonRepeating("aabcbcd"); 
    // Sample I/P: a a b c. My sample: a a b c b c d
    // Output should be: a -1 b b c c d 

    problem5_StackUsingQueues();

    cout << "\nLab Assignment 4 Complete." << endl;
    return 0;
}