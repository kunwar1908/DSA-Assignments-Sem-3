#include <iostream>
#include <algorithm>
#include <vector> // Using vector for dynamic approach in a cleaner way for #2

using namespace std;

// === PROBLEM 1: MENU DRIVEN PROGRAM (CREATE, DISPLAY, INSERT, DELETE, LINEAR SEARCH) ===
const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int current_size = 0;

void createArray() {
    cout << "\n--- 1. CREATE ---" << endl;
    cout << "Enter the number of elements (max " << MAX_SIZE << "): ";
    if (!(cin >> current_size) || current_size < 0 || current_size > MAX_SIZE) {
        cout << "Invalid size. Setting size to 0." << endl;
        current_size = 0;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        return;
    }

    cout << "Enter " << current_size << " integer elements:" << endl;
    for (int i = 0; i < current_size; ++i) {
        cout << "Element " << i + 1 << ": ";
        if (!(cin >> arr[i])) {
            cout << "Invalid input. Skipping element." << endl;
            arr[i] = 0; // Default to 0
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Array created successfully." << endl;
}

void displayArray() {
    cout << "\n--- 2. DISPLAY ---" << endl;
    if (current_size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements: [";
    for (int i = 0; i < current_size; ++i) {
        cout << arr[i] << (i == current_size - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

void insertElement() {
    cout << "\n--- 3. INSERT ---" << endl;
    if (current_size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }

    int element, position;
    cout << "Enter the element to insert: ";
    if (!(cin >> element)) return;
    cout << "Enter the position to insert at (0 to " << current_size << "): ";
    if (!(cin >> position)) return;

    if (position < 0 || position > current_size) {
        cout << "Invalid position." << endl;
        return;
    }

    // Shift elements to the right
    for (int i = current_size; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert and update size
    arr[position] = element;
    current_size++;
    cout << "Element " << element << " inserted at position " << position << "." << endl;
}

void deleteElement() {
    cout << "\n--- 4. DELETE ---" << endl;
    if (current_size == 0) {
        cout << "Array is empty. Nothing to delete." << endl;
        return;
    }

    int position;
    cout << "Enter the position to delete from (0 to " << current_size - 1 << "): ";
    if (!(cin >> position)) return;

    if (position < 0 || position >= current_size) {
        cout << "Invalid position." << endl;
        return;
    }

    int deleted_element = arr[position];

    // Shift elements to the left
    for (int i = position; i < current_size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    current_size--;
    cout << "Element " << deleted_element << " deleted from position " << position << "." << endl;
}

void linearSearch() {
    cout << "\n--- 5. LINEAR SEARCH ---" << endl;
    if (current_size == 0) {
        cout << "Array is empty. Cannot search." << endl;
        return;
    }

    int key;
    cout << "Enter the element to search: ";
    if (!(cin >> key)) return;

    for (int i = 0; i < current_size; ++i) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at position " << i << "." << endl;
            return;
        }
    }
    cout << "Element " << key << " not found in the array." << endl;
}

void menuDrivenProgram() {
    int choice;
    do {
        cout << "\n===============================" << endl;
        cout << "  PROBLEM 1: ARRAY OPERATIONS" << endl;
        cout << "===============================" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // Trigger invalid choice
        }

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting Array Menu." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

// === PROBLEM 2: REMOVE DUPLICATE ELEMENTS ===
void removeDuplicates() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: REMOVE DUPLICATES" << endl;
    cout << "======================================" << endl;

    // Example using C++ vectors for flexibility in resizing
    vector<int> data = {5, 2, 8, 2, 5, 1, 9, 8, 10, 5};
    
    cout << "Original vector: [";
    for (int val : data) cout << val << " ";
    cout << "]" << endl;

    if (data.empty()) {
        cout << "Vector is empty." << endl;
        return;
    }

    // 1. Sort the vector (required for std::unique)
    sort(data.begin(), data.end());

    // 2. Use std::unique to move unique elements to the front
    auto new_end = unique(data.begin(), data.end());

    // 3. Erase the duplicated elements (which are now at the end)
    data.erase(new_end, data.end());

    cout << "Vector with unique elements: [";
    for (int val : data) cout << val << " ";
    cout << "]" << endl;
}


// === PROBLEM 3: PREDICT THE OUTPUT ===
void predictOutput() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 3: PREDICT THE OUTPUT" << endl;
    cout << "======================================" << endl;
    
    /*
    int main()
    {
    int i;
    int arr[5] = {1}; // Array initialization
    for (i = 0; i < 5; i++)
    printf("%d", arr[i]);
    return 0;
    }
    */
    
    cout << "Code Analysis:" << endl;
    cout << "1. The array `arr[5]` is initialized as `{1}`." << endl;
    cout << "2. In C/C++, when an array is partially initialized, the remaining elements are automatically set to 0." << endl;
    cout << "3. The array becomes: `{1, 0, 0, 0, 0}`." << endl;
    cout << "4. The loop prints all 5 elements without any spaces or newlines." << endl;
    
    cout << "\nPredicted Output: 10000" << endl;
}


// === PROBLEM 4: IMPLEMENTATION LOGIC ===

// 4a. Reverse the elements of an array
void reverseArray() {
    cout << "\n--- 4a. REVERSE ARRAY ---" << endl;
    int arr_rev[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr_rev) / sizeof(arr_rev[0]);

    cout << "Original array: [";
    for (int i = 0; i < n; ++i) cout << arr_rev[i] << (i == n - 1 ? "" : ", ");
    cout << "]" << endl;

    // Logic: Two-pointer swap
    int start = 0;
    int end = n - 1;
    while (start < end) {
        swap(arr_rev[start], arr_rev[end]);
        start++;
        end--;
    }

    cout << "Reversed array: [";
    for (int i = 0; i < n; ++i) cout << arr_rev[i] << (i == n - 1 ? "" : ", ");
    cout << "]" << endl;
}

// 4b. Find the matrix multiplication
void matrixMultiplication() {
    cout << "\n--- 4b. MATRIX MULTIPLICATION ---" << endl;
    // Matrix A (2x3) * Matrix B (3x2) = Result C (2x2)
    const int R1 = 2, C1 = 3, R2 = 3, C2 = 2;

    int A[R1][C1] = {{1, 2, 3}, {4, 5, 6}};
    int B[R2][C2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[R1][C2] = {0};

    if (C1 != R2) {
        cout << "Multiplication is not possible (Columns of A != Rows of B)." << endl;
        return;
    }

    // Multiplication: C[i][j] = sum(A[i][k] * B[k][j])
    for (int i = 0; i < R1; ++i) { // Rows of C
        for (int j = 0; j < C2; ++j) { // Columns of C
            for (int k = 0; k < C1; ++k) { // Summation variable
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix C (" << R1 << "x" << C2 << "):" << endl;
    for (int i = 0; i < R1; ++i) {
        for (int j = 0; j < C2; ++j) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

// 4c. Find the Transpose of a Matrix
void transposeMatrix() {
    cout << "\n--- 4c. TRANSPOSE OF A MATRIX ---" << endl;
    const int R = 3, C = 2;
    int A[R][C] = {{1, 2}, {3, 4}, {5, 6}}; // 3x2 matrix
    int T[C][R]; // Transpose will be 2x3

    cout << "Original Matrix A (" << R << "x" << C << "):" << endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Transpose logic: T[j][i] = A[i][j]
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            T[j][i] = A[i][j];
        }
    }

    cout << "Transposed Matrix T (" << C << "x" << R << "):" << endl;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; ++j) {
            cout << T[i][j] << "\t";
        }
        cout << endl;
    }
}


// === PROBLEM 5: SUM OF EVERY ROW AND EVERY COLUMN ===
void rowColumnSum() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 5: ROW/COLUMN SUMS" << endl;
    cout << "======================================" << endl;
    const int R = 3, C = 4;
    int matrix[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Matrix (" << R << "x" << C << "):" << endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Calculate Row Sums
    for (int i = 0; i < R; ++i) {
        int rowSum = 0;
        for (int j = 0; j < C; ++j) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of Row " << i + 1 << " (Index " << i << "): " << rowSum << endl;
    }

    // Calculate Column Sums
    for (int j = 0; j < C; ++j) {
        int colSum = 0;
        for (int i = 0; i < R; ++i) {
            colSum += matrix[i][j];
        }
        cout << "Sum of Column " << j + 1 << " (Index " << j << "): " << colSum << endl;
    }
}


int main() {
    // Problem 1 is handled by calling the menu
    menuDrivenProgram();

    // The rest of the problems run automatically after the menu exits
    removeDuplicates();
    
    predictOutput();

    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: MATRIX AND ARRAY LOGIC" << endl;
    cout << "======================================" << endl;
    reverseArray();
    matrixMultiplication();
    transposeMatrix();

    rowColumnSum();

    cout << "\nLab Assignment 1 Complete." << endl;
    return 0;
}