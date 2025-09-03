#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    int topVal = st.top();
    st.pop();

    insertSorted(st, element);

    st.push(topVal);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int topVal = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, topVal);
}

void printStack(stack<int> st) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    cout << "[";
    bool first = true;
    while (!temp.empty()) {
        if (!first) cout << ", ";
        cout << temp.top();
        first = false;
        temp.pop();
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original stack (top to bottom): ";
    printStack(st);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    printStack(st);

    return 0;
}
