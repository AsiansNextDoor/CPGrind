#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    vector<int> lpower(n);
    vector<int> rpower(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        lpower[i] = a[i] + n - (i+1);// 123x
        rpower[i] = a[i] + i;// x123
        x = max(rpower[i], x);
    }

    multiset<int> ms;
    for (int i = 1; i < n; i++) {
        ms.insert(rpower[i]);
    }

    auto it = ms.end(); it--;
    for (int i = 1; i < n; i++) {
        ms.erase(ms.find(rpower[i]));
        ms.insert(lpower[i-1]);
        it = ms.end(); it--;
        x = min(max(*it, a[i]),x);
    }

    cout << x << endl;
}