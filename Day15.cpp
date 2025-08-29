#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(256, -1); 
    int n = s.size();
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        char c = s[right];

        if (lastSeen[c] >= left) {
            left = lastSeen[c] + 1; 
        }

        lastSeen[c] = right; 
        maxLen = max(maxLen, right - left + 1); 
    }

    return maxLen;
}

int main() {
    string S;
    cout << "Enter string: ";
    cin >> S;

    cout << lengthOfLongestSubstring(S) << endl;
    return 0;
}
