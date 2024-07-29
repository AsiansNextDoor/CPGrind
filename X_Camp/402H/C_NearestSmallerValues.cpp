#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<vector<int>> stk;
    stk.push({0, 0});
    for (int i = 0; i < n; i++) {
        while (stk.top()[0] >= a[i]) stk.pop();
        cout << stk.top()[1] << " ";
        stk.push({a[i], i+1});
    }
}