#include <iostream>
#include <vector>
using namespace std;

// Function to find the duplicate number
int findDuplicate(const vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    fast = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 3, 4, 2, 2},
        {3, 1, 3, 4, 2},
        {1, 1},
        {1, 4, 4, 2, 3},
    };
    
    for (auto &arr : testCases) {
        cout << "Duplicate number in [";
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << (i+1 < arr.size() ? ", " : "");
        }
        cout << "] is: " << findDuplicate(arr) << endl;
    }

    return 0;
}
