#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, m; 
vector<int> barns;
vector<vector<int>> apps;
vector<int> diff;

bool check(int x) {
    diff.clear();
    diff.resize(n+1, 0);
    
    for (int i = 0; i <= x; i++) {
        int b = apps[i][0], left = apps[i][1], right = apps[i][2];
        diff[left-1] += b, diff[right] -= b;
    }
    
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i-1];
    }
    
    for (int i = 0; i < n; i++) {
        if (barns[i] < diff[i]) return true;
    }
    return false;
}

signed main() {
    IOS;
    cin >> n >> m;
    barns.resize(n);
    for (int i = 0; i < n; i++) cin >> barns[i];
    apps.resize(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> apps[i][0] >> apps[i][1] >> apps[i][2]; // barns, start, end
    }

    int l = 0, r = m, ans = -1;
    while (l < r) {
        //cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        //cout << "mid: " << mid << endl;
        if (check(mid)) {
            ans = mid;
            r = mid;
            //cout << ans << endl;
        }
        else {
            l = mid + 1;
        }
    }
    
    if (ans == -1) cout << 0 << endl;
    else {
        cout << -1 << endl;
        cout << ans+1 << endl;
    }
}