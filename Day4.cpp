#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i = 0;
        int j = gap;

        while (j < m + n) {
            int val1, val2;

            if (i < m) val1 = arr1[i];
            else val1 = arr2[i - m];

            if (j < m) val2 = arr1[j];
            else val2 = arr2[j - m];

            if (val1 > val2) {
                if (i < m && j < m) swap(arr1[i], arr1[j]);
                else if (i < m && j >= m) swap(arr1[i], arr2[j - m]);
                else swap(arr2[i - m], arr2[j - m]);
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    mergeArrays(arr1, arr2);

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
