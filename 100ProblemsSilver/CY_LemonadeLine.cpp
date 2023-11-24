#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    int n; cin >> n;
    
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    
    sort(cows.rbegin(), cows.rend());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] >= i) {
            ans++;
        }
    }
    
    cout << ans << endl;
}