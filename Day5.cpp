#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> leaders;
    int max_so_far = INT_MIN;

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] >= max_so_far) {
            leaders.push_back(arr[i]);
            max_so_far = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);
    
    cout << "Leaders: ";
    for(int x : leaders){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
