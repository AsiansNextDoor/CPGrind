#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<vector<int>> adj(2e5+1);

int longest = 0;
int lnode = 1;
int cur = 0;
void dfs(int u, int p) {
    for (int v: adj[u]) {
        if (v == p) continue;
        cur++;
        dfs(v, u);
        cur--;
    }
    if (cur > longest) {
        longest = cur;
        lnode = u;
    }
}

signed main() {
    IOS;

    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    dfs(lnode, 0);
    cout << longest << endl;
}