#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> tree;
vector<vector<int>> subnodes;

int dfs(int node) {
    int snodes = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        int s = dfs(tree[node][i]);
        subnodes[node].push_back(s);
        snodes += s;
    }
    return snodes;
}

signed main() {
    ll t; cin >> t;
    while (t--) {
        int n; cin >> n;

        tree.clear(); tree.resize(n+1);
        subnodes.clear(); subnodes.resize(n+1);
        
        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            tree[p].push_back(i);
        }
        dfs(1);

        int k = 0, node = 1;
        int ans = 0;
        while (true) {
            int maxn = 0, tot = 0, maxi;

            if (subnodes[node].size() == 0) break;
            for (int i = 0; i < subnodes[node].size(); i++) {
                if (subnodes[node][i] > maxn) {
                    maxn = subnodes[node][i];
                    maxi = i;
                }
                tot += subnodes[node][i];
            }

            if (maxn - k > tot - maxn) {
                node = tree[node][maxi];
                ans += tot - maxn;
                k += tot - maxn - 1;
                if (k == -1) k++;
            }
            else {
                ans += (tot-k)/2;
                break;
            }
        }

        cout << ans << endl;
    }
}