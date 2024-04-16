#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        map<char, int> m;
        for (char i = 'a'; i != 'z'; i++) {
            m[i] = -1;
        }
        m['z'] = -1;
        
        int dist = n - k;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            char cur = s[i];
            if (m[cur] == -1) m[cur] = i;
            else if (i - m[cur] <= dist) ans = false;
            m[cur] = i;
        }
        
        if (ans == true) cout << "Yes" << endl;
        else cout << "No" << endl
    }
}