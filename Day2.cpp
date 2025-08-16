#include <iostream>
#include <vector>
using namespace std;

int findMissNumber(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        //if the missing number is in the left half
        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // If missing number is n
    return arr.size() + 1;
}

int main() {
    vector<int> arr = {1, 2, 4, 5}; // Sorted array i/p
    cout << "Missing number is: " << findMissNumber(arr) << endl;
    return 0;
}
