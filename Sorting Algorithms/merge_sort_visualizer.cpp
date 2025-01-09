#include <iostream>
#include <vector>
#include <iomanip> // For formatting output
using namespace std;

// Function to display the array
void displayArray(const vector<int>& arr, int start, int end) {
    for (int i = 0; i < arr.size(); i++) {
        if (i >= start && i <= end) {
            cout << "[" << setw(2) << arr[i] << "] ";
        } else {
            cout << setw(3) << arr[i] << "  ";
        }
    }
    cout << endl;
}

// Function to merge two sorted subarrays
void merge(vector<int>& arr, int start, int mid, int end) {
    cout << "Merging subarrays: ";
    displayArray(arr, start, end);

    vector<int> temp;
    int i = start, j = mid + 1;

    // Merge the two subarrays
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right subarray
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }

    cout << "After merging: ";
    displayArray(arr, start, end);
    cout << "---------------------------------------" << endl;
}

// Recursive function to implement Merge Sort
void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return; // Base case: Single element is already sorted
    }

    int mid = (start + end) / 2;

    // Sort the left half
    cout << "Sorting left: ";
    displayArray(arr, start, mid);
    mergeSort(arr, start, mid);

    // Sort the right half
    cout << "Sorting right: ";
    displayArray(arr, mid + 1, end);
    mergeSort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
}

// Main function
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    displayArray(arr, 0, arr.size() - 1);
    cout << "---------------------------------------" << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    displayArray(arr, 0, arr.size() - 1);
    return 0;
}
