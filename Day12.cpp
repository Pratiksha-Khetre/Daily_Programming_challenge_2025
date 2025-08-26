#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c); 
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false; 
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s1 = "[{()}]";
    string s2 = "[(])";
    string s3 = "{[()]}()[]";

    cout << (sol.isValid(s1) ? "true" : "false") << endl;  
    cout << (sol.isValid(s2) ? "true" : "false") << endl;  
    cout << (sol.isValid(s3) ? "true" : "false") << endl;  

    return 0;
}
