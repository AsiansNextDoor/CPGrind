#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second
int n, m, k, s; 
vector<int> mina, minb;
vector<int> t1, t2;
bool check(int x) {
    int ma = mina[x], mb = minb[x];
    
    // cout << ma << " " << mb << endl;
    
    int i = 0, ans = 0;
    while (i < t1.size() && t1[i] * ma <= s) {
        auto i2 = upper_bound(t2.begin(), t2.end(), (s - ma * t1[i]) / mb);
        i2--;
        if (i2 == t2.end()) ans = max(i+1, ans);
        else ans = max((int)(i2-t2.begin()) + i + 2, ans);
        i++;
    }

    auto i2 = upper_bound(t2.begin(), t2.end(), s / mb); i2--;
    if (i2 != t2.end()) ans = max((int)(i2-t2.begin()) + 1, ans);

    // cout << "ans: " << ans << endl;
    if (ans >= k) return true;
    return false;
}

int main() {
    cin >> n >> m >> k >> s;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int,int>> t3, t4;
    for (int i = 0; i < m; i++) {
        int ty, c; cin >> ty >> c;
        if (ty == 1) {
            t1.push_back(c);
            t3.push_back({c, i+1});
        }
        else {
            t2.push_back(c);
            t4.push_back({c, i+1});
        }
    }

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    sort(t3.begin(), t3.end());
    sort(t4.begin(), t4.end());

    for (int i = 1; i < t1.size(); i++) t1[i] += t1[i-1];
    for (int i = 1; i < t2.size(); i++) t2[i] += t2[i-1];

    
    mina.resize(n, a[0]), minb.resize(n, b[0]);
    for (int i = 0; i < n; i++) {
        mina[i] = min(a[i], mina[i]);
        minb[i] = min(b[i], minb[i]);
    }

    int l = 0, r = n-1;

    // cout << "***" << endl;
    // for (int i = 0; i < t1.size(); i++) cout << t1[i] << " ";
    // cout << endl;
    // for (int i = 0; i < t2.size(); i++) cout << t2[i] << " ";
    // cout << endl;
    // cout << "***" << endl;
    

    while (l < r) {
        int mid = (l + r) / 2;
        int ma = mina[mid], mb = minb[mid];
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    if (l >= n) {
        cout << -1 << endl;
        return 0;
    }
    l++;
    cout << l << endl;
    l--;

    int ma = mina[l], mb = minb[l];
    
    // cout << ma << " " << mb << endl;

    int maxi, maxj;
    int i = 0, ans = 0;
    while (i < t1.size() && t1[i] * ma <= s) {
        auto i2 = upper_bound(t2.begin(), t2.end(), (s - ma * t1[i]) / mb);
        i2--;
        if (i2 == t2.end()) {
            if (ans < i+1) {
                ans = i+1;
                maxi = i;
                maxj = -1;
            }
        }
        else {
            if (ans < (int)(i2-t2.begin()) + i + 2) {
                ans = (int)(i2-t2.begin()) + i + 2;
                maxi = i;
                maxj = (int)(i2-t2.begin()) + 1;
            }
        }
        i++;
    }
    
    auto i2 = upper_bound(t2.begin(), t2.end(), s / mb); i2--;
    if (i2 != t2.end()) {
        if (ans > (int)(i2-t2.begin()) + 1) {
            maxi = -1;
            maxj = (int)(i2-t2.begin()) + 1;
        }
    }
    if (maxi == -1 )

    if (maxi != -1) {
        int day;
        for (int i = 0; i < n; i++) {
            if (a[i] == mina[l]) {
                day = i + 1;
                break;
            }
        }

        for (int i = 0; i <= maxi; i++) {
            cout << t3[i].s << " " << day << endl;
        }
        
    }

    if (maxj != -1) {
        int day;
        
        for (int i = 0; i < n; i++) {
            if (b[i] == minb[l]) {
                day = i + 1;
                break;
            }
        }
        for (int i = 0; i <= maxj; i++) {
            cout << t4[i].s << " " << day << endl;
        }
        
    }
}