#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string plog; cin >> plog;
        
        vector<int> v(26);
        for (int i = 1; i <= 26; i++) {
            v[i-1] = i;
        }
        
        for (int i = 0; i < n; i++) {
            v[plog[i] - 'A']--;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i] <= 0) ans++;
        }
        
        cout << ans << endl;
    }
}