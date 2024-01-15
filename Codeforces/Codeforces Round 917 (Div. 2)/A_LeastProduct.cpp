#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool zero = false;
        int sign = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) zero = true;
            else if (a[i] < 0) sign = 1 - sign;
        }
        
        if (zero || sign) cout << 0 << endl;
        else {
            cout << 1 << endl;
            cout << 1 << " " << 0 << endl;
        }
    }
}