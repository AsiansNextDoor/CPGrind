#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<vector<int>> tree;
vector<int> ans;

int dfs(int u) {
    for (int i: tree[u]) {
        ans[u] += dfs(i);
    }
    ans[u]++;
    return ans[u];
}

signed main() {
    IOS;

    int n; cin >> n;
    tree.resize(n+1);
    ans.resize(n+1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        tree[p].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
}