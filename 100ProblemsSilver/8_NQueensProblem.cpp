#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int n, ans = 0;
set<int> col;
set<int> d1; // equal differences
set<int> d2; // equal sums
void dfs(int r) {
    for (int c = 1; c <= n; c++) {
        int d1val = r - c;
        int d2val = r + c;
        if (col.find(c) != col.end()) continue;
        if (d1.find(d1val) != d1.end()) continue;
        if (d2.find(d2val) != d2.end()) continue;
        if (r == n) ans++;
        else {
            col.insert(c);
            d1.insert(d1val);
            d2.insert(d2val);
            dfs(r + 1);
            col.erase(col.find(c));
            d1.erase(d1.find(d1val));
            d2.erase(d2.find(d2val));
        }
    }
}

signed main() {
    IOS;

    cin >> n;
    dfs(1);
    
    cout << ans << endl;
}