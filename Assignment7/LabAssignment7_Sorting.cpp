#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Utility function to print the vector
template <typename T>
void printVector(const vector<T>& arr, const string& title) {
    cout << title << " [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

// =================================================================
// PROBLEM 1: STANDARD SORTING TECHNIQUES
// =================================================================

// 1a. Selection Sort (O(n^2))
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// 1b. Insertion Sort (O(n^2) average/worst, O(n) best)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, 
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 1c. Bubble Sort (O(n^2))
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization
    }
}

// 1d. Merge Sort (O(n log n)) - Merge function
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) arr[k++] = L[i++];

    // Copy the remaining elements of R[], if any
    while (j < n2) arr[k++] = R[j++];
}

// 1d. Merge Sort - Main function
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Midpoint

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// 1e. Quick Sort (O(n log n) average, O(n^2) worst) - Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the pivot (last element)
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 1e. Quick Sort - Main function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void problem1_StandardSorts() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 1: STANDARD SORTING ALGORITHMS" << endl;
    cout << "======================================" << endl;

    vector<int> original = {5, 2, 8, 1, 9, 4, 7, 3};
    vector<int> arr;

    // a. Selection Sort
    arr = original;
    printVector(arr, "Original: ");
    selectionSort(arr);
    printVector(arr, "a. Selection Sort: ");

    // b. Insertion Sort
    arr = original;
    insertionSort(arr);
    printVector(arr, "b. Insertion Sort: ");

    // c. Bubble Sort
    arr = original;
    bubbleSort(arr);
    printVector(arr, "c. Bubble Sort: ");

    // d. Merge Sort
    arr = original;
    mergeSort(arr, 0, arr.size() - 1);
    printVector(arr, "d. Merge Sort: ");

    // e. Quick Sort
    arr = original;
    quickSort(arr, 0, arr.size() - 1);
    printVector(arr, "e. Quick Sort: ");
}

// =================================================================
// PROBLEM 2: IMPROVED SELECTION SORT (Dual Selection Sort)
// =================================================================
// Finds both min and max in one pass and places them at both ends
void dualSelectionSort(vector<int>& arr) {
    int n = arr.size();
    // i: start index, j: end index
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min_val = arr[i];
        int max_val = arr[i];
        int min_idx = i;
        int max_idx = i;

        // Find min and max in the unsorted segment arr[i...j]
        for (int k = i; k <= j; k++) {
            if (arr[k] < min_val) {
                min_val = arr[k];
                min_idx = k;
            }
            if (arr[k] > max_val) {
                max_val = arr[k];
                max_idx = k;
            }
        }

        // --- Placement of Minimum ---
        // Swap the found minimum element with arr[i]
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
        
        // --- Placement of Maximum ---
        // CRITICAL STEP: After the min swap, if the maximum element was located 
        // at the original 'i' position, it has now moved to 'min_idx'. We must 
        // update max_idx to its new location before swapping with arr[j].
        if (max_idx == i) {
            max_idx = min_idx; 
        }

        // Swap the found maximum element (at max_idx) with arr[j]
        if (max_idx != j) {
            swap(arr[j], arr[max_idx]);
        }
    }
}

void problem2_DualSelectionSort() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: IMPROVED SELECTION SORT (DUAL)" << endl;
    cout << "======================================" << endl;

    vector<int> arr = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    printVector(arr, "Original Array: ");

    dualSelectionSort(arr);
    printVector(arr, "Sorted Array:   ");
}

// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    // Problem 1: Standard Sorting Techniques
    problem1_StandardSorts();

    // Problem 2: Improved Selection Sort
    problem2_DualSelectionSort();

    cout << "\nLab Assignment 7 Complete. All 7 Assignments are solved." << endl;
    return 0;
}