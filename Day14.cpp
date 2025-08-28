#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostK(string &s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int count = 0;
        unordered_map<char, int> freq;

        for (right = 0; right < n; right++) {
            freq[s[right]]++;

            while ((int)freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            count += (right - left + 1);
        }
        return count;
    }

    int substrCount(string s, int k) {
        if (k == 0) return 0;
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s = "pqpqs";
    int k = 2;
    cout << sol.substrCount(s, k) << endl;  
    return 0;
}
