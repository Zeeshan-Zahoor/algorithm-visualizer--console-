#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search(vector <int> &arr, int st, int end, int target) {
    int mid = st + (end-st)/2;  // find the mid of the array
    while (st <= end) {
        if(arr[mid] == target) {
        // printArr(arr, st, mid, target); // print the color coded array for better understanding
        cout << "Target Found at the Index: \033[32m" << mid << "\033[0m"<< endl;
        return;
        }
    }

}

int main() {
    vector <int> arr = {1, 2, 4, 6, 7, 12, 23, 34, 89};
    int target = 7;
    binary_search(arr, 0, arr.size()-1, target);
    return 0;
}
