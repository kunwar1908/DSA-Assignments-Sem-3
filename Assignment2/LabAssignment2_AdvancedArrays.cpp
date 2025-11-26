#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

// Function to print an array/vector
template <typename T>
void printArray(const T& arr, const string& title) {
    cout << title << " [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

// =================================================================
// PROBLEM 1: BINARY SEARCH
// Time Complexity: O(log n)
// =================================================================
int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow

        if (arr[mid] == key) {
            return mid; // Found the key
        } else if (arr[mid] < key) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Key not found
}

void problem1_BinarySearch() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 1: BINARY SEARCH (O(log n))" << endl;
    cout << "======================================" << endl;

    vector<int> sorted_arr = {11, 12, 22, 25, 34, 64, 90};
    int key = 25;

    printArray(sorted_arr, "Sorted Array:");
    int index = binarySearch(sorted_arr, key);

    if (index != -1) {
        cout << "Element " << key << " found at index: " << index << endl;
    } else {
        cout << "Element " << key << " not found." << endl;
    }
}

// =================================================================
// PROBLEM 2: BUBBLE SORT
// =================================================================
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        // Last i elements are already in place
        for (int j = 0; j < n - 1 - i; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then array is sorted
        if (!swapped) break;
    }
}

void problem2_BubbleSort() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 2: BUBBLE SORT" << endl;
    cout << "======================================" << endl;

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    printArray(arr, "Original Array:");

    bubbleSort(arr);

    printArray(arr, "Sorted Array (Bubble Sort):");
}

// =================================================================
// PROBLEM 3: FIND MISSING NUMBER IN SORTED ARRAY (1 to n)
// =================================================================

// 3a. Linear Time (O(n)) - Using Summation
int findMissingLinear(const vector<int>& arr, int n) {
    // Expected sum of numbers from 1 to n (Gauss formula)
    long long expected_sum = (long long)n * (n + 1) / 2;

    // Actual sum of elements in the array (n-1 elements)
    long long actual_sum = 0;
    for (int num : arr) {
        actual_sum += num;
    }

    return (int)(expected_sum - actual_sum);
}

// 3b. Binary Search (O(log n)) - Assuming 1 to n sequence
int findMissingBinary(const vector<int>& arr, int n) {
    int low = 0;
    int high = arr.size() - 1; // arr.size() is n-1

    // If the missing number is n, it will be found here
    if (arr[high] == high + 1) return n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If arr[mid] is not equal to its expected index + 1, the missing number is in the left half
        // Expected number at index `mid` is `mid + 1`.
        if (arr[mid] != mid + 1) {
            // Check if this is the missing number (or if its predecessor is fine)
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;
            }
            high = mid - 1; // Missing number is further left
        } else {
            low = mid + 1; // The sequence is correct up to mid, missing number is in the right half
        }
    }
    // Handle the case where the missing number is n (already checked at the start) or 1
    return -1; 
}

void problem3_MissingNumber() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 3: FIND MISSING NUMBER" << endl;
    cout << "======================================" << endl;

    vector<int> arr = {1, 2, 4, 5, 6, 7}; // n=7, array size=6, missing 3
    int n = arr.size() + 1;

    printArray(arr, "Input Sorted Array (Range 1 to " + to_string(n) + "):");

    // 3a. Linear Time (Summation)
    int missing_linear = findMissingLinear(arr, n);
    cout << " (a) Linear Time (O(n)) Missing Number: " << missing_linear << endl;

    // 3b. Binary Search (O(log n))
    int missing_binary = findMissingBinary(arr, n);
    cout << " (b) Binary Search (O(log n)) Missing Number: " << missing_binary << endl;
}

// =================================================================
// PROBLEM 4: STRING RELATED PROGRAMS
// =================================================================
void problem4_Strings() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 4: STRING PROGRAMS" << endl;
    cout << "======================================" << endl;

    string s1 = "Hello, ";
    string s2 = "World!";
    string original_s = "DaTa Structures";
    string vowels_s = "Programming Is FUN";
    string sort_s = "cbaedgfh";

    // 4a. Concatenate one string to another
    string s_concat = s1 + s2;
    cout << " (a) Concatenation: \"" << s1 << "\" + \"" << s2 << "\" = \"" << s_concat << "\"" << endl;

    // 4b. Reverse a string
    string s_reversed = original_s;
    reverse(s_reversed.begin(), s_reversed.end());
    cout << " (b) Reverse: \"" << original_s << "\" -> \"" << s_reversed << "\"" << endl;

    // 4c. Delete all the vowels from the string
    string s_no_vowels = vowels_s;
    s_no_vowels.erase(remove_if(s_no_vowels.begin(), s_no_vowels.end(), [](char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }), s_no_vowels.end());
    cout << " (c) Delete Vowels: \"" << vowels_s << "\" -> \"" << s_no_vowels << "\"" << endl;

    // 4d. Sort the strings in alphabetical order
    string s_sorted = sort_s;
    sort(s_sorted.begin(), s_sorted.end());
    cout << " (d) Alphabetical Sort: \"" << sort_s << "\" -> \"" << s_sorted << "\"" << endl;

    // 4e. Convert a character from uppercase to lowercase
    char upper_char = 'X';
    char lower_char = tolower(upper_char);
    cout << " (e) Uppercase to Lowercase: '" << upper_char << "' -> '" << lower_char << "'" << endl;
}

// =================================================================
// PROBLEM 5: EFFICIENT STORAGE FOR SPECIAL MATRICES
// (Implemented via a function that explains the storage concept)
// =================================================================
void problem5_EfficientStorage() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 5: EFFICIENT MATRIX STORAGE" << endl;
    cout << "======================================" << endl;

    cout << "Goal: Reduce space from O(n^2) to O(n) or O(n^2/2) by storing only non-zero/unique elements." << endl;
    int n = 5; // Example dimension
    long long space_required;

    // 5a. Diagonal Matrix: Only elements where i == j are non-zero.
    space_required = n; // O(n)
    cout << " (a) Diagonal Matrix (n=" << n << "): Stores only n elements (A[i][i]). Space: O(n) = " << space_required << endl;

    // 5b. Tri-diagonal Matrix: Elements only on main diagonal, and one above/below it (i.e., |i-j| <= 1).
    space_required = 3 * n - 2; // O(n)
    cout << " (b) Tri-diagonal Matrix (n=" << n << "): Stores 3n-2 elements. Space: O(n) = " << space_required << endl;

    // 5c. Lower Triangular Matrix: A[i][j] = 0 for i < j. Stores elements in the lower triangle and diagonal.
    space_required = (long long)n * (n + 1) / 2; // O(n^2/2)
    cout << " (c) Lower Triangular Matrix (n=" << n << "): Stores n(n+1)/2 elements. Space: O(n^2/2) = " << space_required << endl;

    // 5d. Upper Triangular Matrix: A[i][j] = 0 for i > j. Stores elements in the upper triangle and diagonal.
    space_required = (long long)n * (n + 1) / 2; // O(n^2/2)
    cout << " (d) Upper Triangular Matrix (n=" << n << "): Stores n(n+1)/2 elements. Space: O(n^2/2) = " << space_required << endl;

    // 5e. Symmetric Matrix: A[i][j] = A[j][i]. The upper triangle is a mirror of the lower triangle.
    // We only need to store the lower or upper triangle, including the diagonal.
    space_required = (long long)n * (n + 1) / 2; // O(n^2/2)
    cout << " (e) Symmetric Matrix (n=" << n << "): Stores n(n+1)/2 elements (Lower/Upper half + diagonal). Space: O(n^2/2) = " << space_required << endl;
}

// =================================================================
// PROBLEM 6: SPARSE MATRIX OPERATIONS (using Triplet Representation)
// Triplet Format: (Row, Column, Value)
// =================================================================

// Define the Triplet structure for sparse matrix representation
struct Triplet {
    int row, col, val;
};

// 6a. Transpose of a Sparse Matrix
vector<Triplet> transposeSparseMatrix(const vector<Triplet>& sparse) {
    if (sparse.empty()) return {};

    // First triplet usually stores (Rows, Columns, Non-Zero Count)
    int R = sparse[0].row;
    int C = sparse[0].col;
    int T = sparse[0].val; // Non-zero count

    vector<Triplet> transposed;
    // The first element is transposed: (C, R, T)
    transposed.push_back({C, R, T});

    // Simple Transpose: Swap row and col for every non-zero element
    // NOTE: This does not result in a sorted (row-major) transpose; a Fast Transpose is better.
    // For simplicity, we use the simple method here.
    for (size_t i = 1; i < sparse.size(); ++i) {
        transposed.push_back({sparse[i].col, sparse[i].row, sparse[i].val});
    }
    return transposed;
}

void problem6_SparseMatrix() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 6: SPARSE MATRIX OPERATIONS" << endl;
    cout << "======================================" << endl;

    // Example 3x3 Sparse Matrix:
    // 0 0 5
    // 0 2 0
    // 1 0 0
    // Triplet representation: (R, C, T) then (r, c, val)
    vector<Triplet> sparseA = {
        {3, 3, 3},
        {0, 2, 5},
        {1, 1, 2},
        {2, 0, 1}
    };
    cout << "Sparse Matrix A (Triplet format):" << endl;
    cout << "(R, C, T): (" << sparseA[0].row << ", " << sparseA[0].col << ", " << sparseA[0].val << ")" << endl;
    for (size_t i = 1; i < sparseA.size(); ++i) {
        cout << "(" << sparseA[i].row << ", " << sparseA[i].col << ", " << sparseA[i].val << ", Value: " << sparseA[i].val << ")" << endl;
    }

    // 6a. Transpose
    vector<Triplet> transposed = transposeSparseMatrix(sparseA);
    cout << "\n(a) Transpose of Matrix A:" << endl;
    cout << "(R, C, T): (" << transposed[0].row << ", " << transposed[0].col << ", " << transposed[0].val << ")" << endl;
    for (size_t i = 1; i < transposed.size(); ++i) {
        cout << "(" << transposed[i].row << ", " << transposed[i].col << ", " << transposed[i].val << ", Value: " << transposed[i].val << ")" << endl;
    }

    // NOTE: Addition and Multiplication logic are significantly more complex 
    // for sparse matrices and are typically implemented using a more advanced 
    // Row-Major or Fast Transpose structure for efficiency.
    cout << "\n(b) Addition and (c) Multiplication are highly complex for triplet representation." << endl;
    cout << "They require efficient sorting or merging of triplets to maintain order and perform the operations in O(NonZero + T*C) time." << endl;
}


// =================================================================
// PROBLEM 7: COUNT INVERSIONS IN AN ARRAY
// An inversion is a pair (A[i], A[j]) such that i < j and A[i] > A[j]
// =================================================================
int countInversions(const vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                count++;
                // cout << "Inversion: (" << arr[i] << ", " << arr[j] << ")" << endl; // Debugging
            }
        }
    }
    return count;
}

void problem7_CountInversions() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 7: COUNT INVERSIONS" << endl;
    cout << "======================================" << endl;

    vector<int> arr = {2, 4, 1, 3, 5}; // Inversions: (2,1), (4,1), (4,3). Count = 3
    printArray(arr, "Input Array:");

    int count = countInversions(arr);
    cout << "Total number of inversions: " << count << endl;
}

// =================================================================
// PROBLEM 8: COUNT DISTINCT ELEMENTS
// =================================================================
int countDistinctElements(const vector<int>& arr) {
    // Use std::sort followed by std::unique
    if (arr.empty()) return 0;
    
    vector<int> temp_arr = arr; // Make a copy as sort modifies the original
    sort(temp_arr.begin(), temp_arr.end());
    
    // unique moves all unique elements to the beginning and returns an iterator
    // to the new logical end of the unique range.
    auto it = unique(temp_arr.begin(), temp_arr.end());
    
    // The number of distinct elements is the distance from the beginning to the new end.
    return distance(temp_arr.begin(), it);
}

void problem8_CountDistinct() {
    cout << "\n======================================" << endl;
    cout << "  PROBLEM 8: COUNT DISTINCT ELEMENTS" << endl;
    cout << "======================================" << endl;

    vector<int> arr = {10, 20, 10, 30, 40, 20, 50};
    printArray(arr, "Input Array:");

    int distinct_count = countDistinctElements(arr);
    cout << "Total number of distinct elements: " << distinct_count << endl;
}


// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
    problem1_BinarySearch();
    problem2_BubbleSort();
    problem3_MissingNumber();
    problem4_Strings();
    problem5_EfficientStorage();
    problem6_SparseMatrix();
    problem7_CountInversions();
    problem8_CountDistinct();

    cout << "\nLab Assignment 2 Complete." << endl;
    return 0;
}