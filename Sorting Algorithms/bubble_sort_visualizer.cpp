// Bubble Sort Visualizer in C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort_visualizer(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // For visualization purposes, print the array at the start of each outer loop iteration.
        cout << "Pass " << i + 1 << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Print final sorted array.
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 8, 6, 2};
    bubble_sort_visualizer(arr);
    return 0;
}
