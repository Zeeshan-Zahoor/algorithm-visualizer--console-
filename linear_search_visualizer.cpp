#include <iostream>
#include <vector>
#include <chrono>
#include <thread>  // For sleep functionality
using namespace std;

void printArr(vector <int> arr, int target) {
    cout << "Array : ";
    for (int element : arr) {
        cout << element << " ";
    }   cout << "\t Target = " << target << endl;
}

void visualize_linear_Search(vector <int> &arr, int target) {
    for (int idx=0; idx<arr.size(); idx++) {
        cout << "\nIteration " << idx+1 << endl;
        printArr(arr, target);   // print the array after each iteration
        cout << "For Index "<<idx<<", Element is "<<arr[idx] << endl;
        if(arr[idx]!=target) {
            cout << "Which is not Equal to Target." << endl;
        } else if(arr[idx] == target) {
            cout << "Which is equal to target." << endl;
            cout << "So, target found at Index " << idx;
            return;
        }
    
        this_thread::sleep_for(chrono::milliseconds(2000));   // set the dalay to 1 second to observe the search.
    }
    cout << "\nTraversed the Complete Array But Target is not Found." << endl;
}

int main() {
    vector <int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    visualize_linear_Search(arr, target);
    
    return 0;
}
