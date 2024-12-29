#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search(vector <int> &arr, int st, int end, int target) {

    while (st <= end) {
        int mid = st + (end-st)/2;  // find the mid of the array
        if(arr[mid] == target) {
            // printArr(arr, st, mid, target); // print the color coded array for better understanding
            cout << "Target Found at the Index: \033[32m" << mid << "\033[0m"<< endl;
            return;
        } else if (arr[mid] < target) {
            cout << "Since the Middle is Less than target, the Target would be in Right Side." << endl;
            cout << "Now Array Would Start from the Middle+1 Element." << endl;
            st = mid + 1;
            // printArr(arr, st, mid, target);
        } else {
            cout << "Since the Middle is Greater than target, the Target would be in Left Side." << endl;
            cout << "Now Array Would End at Middle - 1 Element." << endl;
            end = mid - 1;
            // printArr(arr, st, mid, target);
        }
    }

}

int main() {
    vector <int> arr = {1, 2, 4, 6, 7, 12, 23, 34, 89};
    int target = 12;
    binary_search(arr, 0, arr.size()-1, target);
    return 0;
}
