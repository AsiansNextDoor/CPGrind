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

    int n; cin >> n;
    map<int, map<int, int>> pos;
    map<int, int> occ;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = occ[a[i][0]];
        pos[a[i][0]][occ[a[i][0]]] = i;
        occ[a[i][0]]++;
    }

    sort(a.begin(), a.end());

    int times = 0;
    for (int i = 0; i < n; i++) times = max(pos[a[i][0]][a[i][1]] - i, times);

    cout << times + 1 << endl;
}