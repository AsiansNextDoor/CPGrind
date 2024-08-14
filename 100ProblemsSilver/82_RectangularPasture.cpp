#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

ull MOD = 9e18;

signed main() {
    IOS;

    int n; cin >> n;

    vector<int> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i - 1] * (ull)2;
        pow2[i] %= MOD;
    }

    vector<vector<int>> cows(n, vector<int>(2));
    set<int> xs;
    set<int> ys;
    for (int i = 0; i < n; i++) {
        cin >> cows[i][0] >> cows[i][1];
        xs.insert(cows[i][0]);
        ys.insert(cows[i][1]);
    }

    // coordinate compression
    map<int, int> xc;
    map<int, int> yc;
    int xi = 1, yi = 1;
    for (int x: xs) xc[x] = xi++;
    for (int y: ys) yc[y] = yi++;

    vector<vector<int>> psum(xi, vector<int>(yi, 0));
    for (int i = 0; i < n; i++) {
        cows[i][0] = xc[cows[i][0]];
        cows[i][1] = yc[cows[i][1]];
        psum[cows[i][0]][cows[i][1]]++;
    }

    for (int i = 1; i <= xi; i++) {
        for (int j = 1; j <= yi; j++) {
            psum[i][j] += psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1]; 
        }
    }

    sort(cows.begin(), cows.end());

    int ans = 1 << 
    int px = 0, miny = 0;
    for (int i = 0; i < n; i++) {
        int cx = cows[i][0], cy = cows[i][1];
        if (cx != px) miny = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x = cows[i][0], y = cows[i][1];
            if (y <= cy) continue;
        }
        

        px = cx;
        miny = cy;
    }
}