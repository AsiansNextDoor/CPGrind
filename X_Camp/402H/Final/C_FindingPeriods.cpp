//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

void solve(string s) {
    int n = s.size();
    vector<int> z(n,0);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i + z[i]; z[i]++;
        }
        if (z[i] + i == n) cout<<i<<' ';
    }
    cout << n;
}
signed main(){
    IOS;
    string s; cin >> s;
    solve(s);
}