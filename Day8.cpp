#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    vector<string> words;
    string word;

    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            word += s[i]; 
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) { 
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }

    return result;
}

int main() {
    vector<string> tests = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "    ",
        "word"
    };

    for (string &t : tests) {
        cout << "Input: \"" << t << "\"" << endl;
        cout << "Output: \"" << reverseWords(t) << "\"" << endl;
        cout << "------------------" << endl;
    }

    return 0;
}
