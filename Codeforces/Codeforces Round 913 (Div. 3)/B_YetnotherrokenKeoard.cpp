#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        stack<int> l;
        stack<int> u;
        
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            char s1 = s[i];
            if (s1 == 'B') {
                visited[i] = 1;
                if (!u.empty()) {
                    visited[u.top()] = 1;
                    u.pop();
                }
            }
            else if (s1 == 'b') {
                visited[i] = 1;
                if (!l.empty()) {
                    visited[l.top()] = 1;
                    l.pop();
                }
            }
            else if (isupper(s[i])) {
                u.push(i);
            }
            else {
                l.push(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cout << s[i];
            }
        }
        cout << endl;
    }
}