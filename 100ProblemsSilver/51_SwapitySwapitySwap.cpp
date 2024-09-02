#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    
    vector<int> swaps(n);
    iota(swaps.begin(), swaps.end(), 0);

    while (m--) {
        int l, r; cin >> l >> r;
        l--;
        vector<int> s(swaps.begin() + l, swaps.begin() + r);
        swap_ranges(s.rbegin(), s.rend() , swaps.begin() + l);
    }
    
    vector<int> a(n), cows(n);
    iota(cows.begin(), cows.end(), 0);
    
    int rep = 0;

    vector<vector<int>> forms;
    forms.push_back(cows);
    cows = swaps;
    while (!equal(forms[0].begin(), forms[0].begin() + n, cows.begin())) {
        vector<int> temp = cows;
        for (int i = 0; i < n; i++) cows[i] = temp[swaps[i]];
        forms.push_back(cows);
        rep++;
    }

    for (int i = 0; i < n; i++) cout << forms[(k - 1) % rep][i] + 1 << endl;
}