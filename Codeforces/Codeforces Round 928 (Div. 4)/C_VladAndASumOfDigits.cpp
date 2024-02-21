#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    if (n <= 0) return 0;
    int d = log10(n);
    int w = (d > 0) ? (45 * d * pow(10, d - 1)) : 0;
    int msd = n / pow(10, d);
    return w * msd + (msd * (msd - 1) / 2) * pow(10, d) + msd * (n % (int)(pow(10, d)) + 1) + sumOfDigits(n % (int)(pow(10, d)));
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << sumOfDigits(n) << endl;
    }
}