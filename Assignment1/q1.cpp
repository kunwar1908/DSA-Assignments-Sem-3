#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int current_size = 0;

void createArray() {
    cout << "\n--- 1. CREATE ---" << endl;
    cout << "Enter the number of elements (max " << MAX_SIZE << "): ";
    if (!(cin >> current_size) || current_size < 0 || current_size > MAX_SIZE) {
        cout << "Invalid size. Setting size to 0." << endl;
        current_size = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter " << current_size << " integer elements:" << endl;
    for (int i = 0; i < current_size; ++i) {
        cout << "Element " << i + 1 << ": ";
        if (!(cin >> arr[i])) {
            cout << "Invalid input. Skipping element." << endl;
            arr[i] = 0;
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
    cout << "Enter the element to insert: "; if (!(cin >> element)) return;
    cout << "Enter the position to insert at (0 to " << current_size << "): "; if (!(cin >> position)) return;

    if (position < 0 || position > current_size) { cout << "Invalid position." << endl; return; }
    for (int i = current_size; i > position; --i) arr[i] = arr[i-1];
    arr[position] = element; current_size++;
    cout << "Element " << element << " inserted at position " << position << "." << endl;
}

void deleteElement() {
    cout << "\n--- 4. DELETE ---" << endl;
    if (current_size == 0) { cout << "Array is empty. Nothing to delete." << endl; return; }
    int position; cout << "Enter the position to delete from (0 to " << current_size - 1 << "): "; if (!(cin >> position)) return;
    if (position < 0 || position >= current_size) { cout << "Invalid position." << endl; return; }
    int deleted_element = arr[position];
    for (int i = position; i < current_size - 1; ++i) arr[i] = arr[i + 1];
    current_size--; cout << "Element " << deleted_element << " deleted from position " << position << "." << endl;
}

void linearSearch() {
    cout << "\n--- 5. LINEAR SEARCH ---" << endl;
    if (current_size == 0) { cout << "Array is empty. Cannot search." << endl; return; }
    int key; cout << "Enter the element to search: "; if (!(cin >> key)) return;
    for (int i = 0; i < current_size; ++i) if (arr[i] == key) { cout << "Element " << key << " found at position " << i << "." << endl; return; }
    cout << "Element " << key << " not found in the array." << endl;
}

int main() {
    // Demonstrate the menu-driven functions: create, display, insert, delete, linear search
    createArray();
    displayArray();
    insertElement();
    displayArray();
    deleteElement();
    displayArray();
    linearSearch();
    return 0;
}
