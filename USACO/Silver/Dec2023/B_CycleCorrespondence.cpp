#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, k; cin >> n >> k;
    vector<int> a(k), b(k);
    set<int> cycle;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        cycle.insert(a[i]);
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        cycle.insert(b[i]);
    }
    int outside = n - cycle.size();

    vector<int> pos_a(n, -1);
    vector<int> shift(k, -1);
    for (int i = 0; i < k; i++) pos_a[a[i]] = i;

    for (int i = 0; i < k; i++) {
        if (pos_a[b[i]] == -1) continue;
        int apos = pos_a[b[i]];
        int bpos = i;

        if (bpos >= apos) shift[i] = bpos-apos;
        else shift[i] = k - (apos-bpos);
    }

    map<int,int> inside;
    for (int i = 0; i < k; i++) inside[shift[i]]++;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(inside[i], ans);
    }
    
    reverse(b.begin(), b.end());
    
    shift.clear();
    shift.resize(k, -1);
    for (int i = 0; i < k; i++) {
        if (pos_a[b[i]] == -1) continue;
        int apos = pos_a[b[i]];
        int bpos = i;

        if (bpos >= apos) shift[i] = bpos-apos;
        else shift[i] = k - (apos-bpos);
    }

    inside.clear();
    for (int i = 0; i < k; i++) inside[shift[i]]++;

    for (int i = 0; i < n; i++) {
        ans = max(inside[i], ans);
    }
    ans += outside;
    cout << ans << endl;
}