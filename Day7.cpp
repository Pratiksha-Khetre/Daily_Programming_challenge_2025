#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; 

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5},
        {1, 1, 1},
        {5},
        {2, 0, 2},
        {0, 0, 0, 0},  
        {1, 2, 3, 4},   
        {4, 3, 2, 1}    
    };

    for (auto &tc : testCases) {
        cout << "Input: ";
        for (int h : tc) cout << h << " ";
        cout << "\nOutput: " << sol.trap(tc) << "\n\n";
    }

    return 0;
}
