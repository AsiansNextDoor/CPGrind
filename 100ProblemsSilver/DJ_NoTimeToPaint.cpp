#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    
    vector<int> pre(n+1, 0);
    vector<int> suf(n+1, 0);
    
    string colors; cin >> colors;
    
    stack<char> s;
    for (int i = 0; i < n; i++) {
        char c = colors[i];
        while (!s.empty() && s.top() > c) {
            s.pop();
        }
        if (s.empty() || s.top() < c) {
            s.push(colors[i]);
            pre[i+1]++;
        }
        pre[i+1] += pre[i];
    }
    reverse(colors.begin(), colors.end());
    
    stack<char> s2;
    for (int i = 0; i < n; i++) {
        char c = colors[i];
        while (!s2.empty() && s2.top() > c) {
            s2.pop();
        }
        if (s2.empty() || s2.top() < c) {
            s2.push(colors[i]);
            suf[i+1]++;
        }
        suf[i+1] += suf[i];
    }
    
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pre[a-1] + suf[n-b] << endl;
    }
}