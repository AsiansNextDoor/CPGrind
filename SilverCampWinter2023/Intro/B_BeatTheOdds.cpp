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
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) even++;
            else odd++;
        }
        
        cout << min(even, odd) << endl;
    }
 }