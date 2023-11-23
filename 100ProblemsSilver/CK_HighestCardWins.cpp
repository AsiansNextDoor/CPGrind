#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    set<int> a;
    vector<int> b;
    
    for (int i = 1; i <= 2*n; i++) {
        a.insert(i);
    }
    
    for (int i = 0; i < n; i++) {
        int j; cin >> j;
        a.erase(a.find(j));
        b.push_back(j);
    }
    
    sort(b.rbegin(), b.rend());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = a.lower_bound(b[i]);
        if (it != a.end()) {
            a.erase(it);
            ans++;
        }
    }
    
    cout << ans << endl;
}