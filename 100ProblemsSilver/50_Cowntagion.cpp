#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

int days = 0;
vector<vector<int>> adj;
void dfs(int u, int p) {
    int c = 1;
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        days++;
        c++;
    }

    int cows = 1;
    while (cows < c) {
        cows *= 2;
        days++;
    }
    return;
}

signed main() {
    IOS;

    int n; cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << days << endl;
}