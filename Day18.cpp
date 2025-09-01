#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    int sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    long long N;
    cin >> N;

    cout << countDivisors(N) << endl;
    return 0;
}
