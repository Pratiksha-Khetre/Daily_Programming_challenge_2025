#include <bits/stdc++.h>
using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int carry = 0;

    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result = char((sum % 10) + '0') + result;
    }
    if (carry) result = char(carry + '0') + result;

    return result;
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<string> dp(n + 1);
    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; i++) {
        dp[i] = addStrings(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n] << endl;
    return 0;
}
