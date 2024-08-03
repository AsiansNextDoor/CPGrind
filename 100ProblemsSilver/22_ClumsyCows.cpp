#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    string s; cin >> s;

    int maxn = 0, net = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') net++;
        else net--;
        maxn = max(maxn, net);
    }

    if (net >= 0) {
        cout << (max(net, maxn) + 1) / 2 << endl;
    }
    else {
        cout << (maxn + 1) / 2 + (abs(net) + (maxn + 1) / 2 + 1) / 2 << endl;
    }
}