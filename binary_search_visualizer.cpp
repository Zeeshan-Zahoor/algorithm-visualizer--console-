#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>  // For sleep functionality

using namespace std;

// Function for visualization of the array with color-coded elements
void printArr(const vector<int>& arr, int mid, int target) {
    cout << "Array: ";
    for (int i = 0; i < arr.size(); i++) {
        if (i == mid) {
            // Highlight the middle element
            cout << "\033[32m" << arr[i] << "\033[0m, ";
        } else if ((arr[mid] < target && i <= mid) || (arr[mid] > target && i > mid)) {
            // Highlight irrelevant elements in red
            cout << "\033[31m" << arr[i] << "\033[0m, ";
        } else {
            // Highlight relevant elements in green
            cout << "\033[32m" << arr[i] << "\033[0m, ";
        }
    }
    cout << endl;
}

// Function for binary search with visualization
void binarySearch(const vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    //print the whole array in white first
    cout << "Array: ";
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << ", ";
    } cout << endl;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Calculate the middle index


        if (arr[mid] == target) {
            cout << "Target Found at the Index: \033[32m" << mid << "\033[0m" << endl;
            return;
        } else if (arr[mid] < target) {
            cout << "Since the middle element is less than the target, search in the right subarray.\n";
            st = mid + 1;
        } else {
            cout << "Since the middle element is greater than the target, search in the left subarray.\n";
            end = mid - 1;
        }
        // Visualize the current state of the array
        printArr(arr, mid, target);
    
    this_thread::sleep_for(chrono::milliseconds(3000));   // set the dalay to 3 second to observe the search.
    }

    // If the loop exits, the target is not found
    cout << "Target not found in the array.\n";
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 7, 12, 23, 34, 89}; // Sorted array
    int target = 12; // Element to search

    cout << "\nStarting Binary Search for Target: \033[32m" << target << "\033[0m\n\n";
    binarySearch(arr, target);

    return 0;
}
