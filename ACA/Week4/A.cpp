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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int most = 0;

        set<int> s;
        for (int i = n - 1; i >= 0; i--) {
            s.insert(a[i]);
            if (most + 1 == s.size()) {
                most++;
            }
            else break;
        }

        cout << n - most << endl;
    }
}