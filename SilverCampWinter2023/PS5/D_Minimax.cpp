#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

int n, m, i1, i2;

vector<vector<int>> a;
bool check(int x) {
    set<int> bits;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int bit = 0;
        for (int j = 0; j < m; j++) {
            bit = (bit << 1);
            if (a[i][j] >= x) {
                bit++;
            }
        }
        bits.insert(bit);
        answer.push_back(bit);
    }


    bool valid = false;
    int mask1, mask2;
    for (auto i = bits.begin(); i != bits.end(); i++) {
        for (auto j = bits.begin(); j != bits.end(); j++) {
            //cout << *i << " " << *j << endl;
            if ((*i | *j) == (1 << m)-1) {
                valid = true;
                mask1 = *i;
                mask2 = *j;
            }
        }
    }

    if (valid) {
        for (int i = 0; i < n; i++) {
            if (answer[i] == mask1) i1 = i+1;
            if (answer[i] == mask2) i2 = i+1;
        }
        return true;
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int l = 0, r = 1e9;
    int a1 = 0, a2 = 0;
    if (check(0)) {
        a1 = i1;
        a2 = i2;
    }
    int ans = 0;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        //cout << "mid: " << mid << endl;
        if (check(mid)) {
            //cout << l << endl;
            l = mid;
            if (ans < mid){
                ans = mid;
                a1 = i1;
                a2 = i2;
            }
        }
        else {
            r = mid - 1;
        }
    }
    //cout << ans << endl;

    cout << a1 << " " << a2 << endl;
}