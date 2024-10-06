//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        set<int> s;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            m[a]++;
            s.insert(a);
        }
        
        int cost = 0;
        for (int cur: s) {
            if (m[cur] > c) cost += c;
            else cost += m[cur];
        }

        cout << cost << endl;
    }
}