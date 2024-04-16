#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<pair<int,int>> jswaps(m);
    for (int i = 0; i < m; i++) {
        cin >> jswaps[i].f >> jswaps[i].s;
        jswaps[i].f--;
        jswaps[i].s--;
    }
    vector<pair<int,int>> mswaps(q);
    for (int i = 0; i < q; i++) {
        cin >> mswaps[i].f >> mswaps[i].s;
        mswaps[i].f--;
        mswaps[i].s--;
    }
    
    vector<int> ans = a;
    sort(ans.begin(), ans.end());
    for (int i = m-1; i >= 0; i--) {
        swap(ans[jswaps[i].f], ans[jswaps[i].s]);
    }
    
    int match = 0;
    vector<bool> equal(n, false);
    for (int i = 0; i < n; i++) {
        if (a[i] == ans[i]) {
            match++;
            equal[i] = true;
        }
    }
    
    string days = "";
    for (int i = 0; i < q; i++) {
        int s1 = mswaps[i].f, s2 = mswaps[i].s;
        if (a[s1] == ans[s2]) {
            if (equal[s2] == false) match++;
            equal[s2] = true;
        }
        else {
            if (equal[s2] == true) match--;
            equal[s2] = false;
        }
        
        if (a[s2] == ans[s1]) {
            if (equal[s1] == false) match++;
            equal[s1] = true;
        }
        else {
            if (equal[s1] == true) match--;
            equal[s1] = false;
        }
        
        swap(a[s1], a[s2]);
        if (match == n) days += "Y";
        else days += "N";
    }
    
    cout << days << endl;
}