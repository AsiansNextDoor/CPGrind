#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<pair<ll, ll>>> adj;
vector<ll> pop;
vector<ll> cost;

void dfs(ll node, ll parent, ll dist) {
    cost[node] = dist * pop[node];
    for (auto neighbor : adj[node]) {
        ll nextNode = neighbor.first;
        ll edgeWeight = neighbor.second;
        if (nextNode != parent) {
            dfs(nextNode, node, dist + edgeWeight);
            cost[node] += cost[nextNode];
        }
    }
}

int main() {
    ll n;
    cin >> n;
    adj.resize(n + 1);
    pop.resize(n + 1);
    cost.resize(n + 1);

    for (ll i = 1; i <= n; ++i) {
        cin >> pop[i];
    }

    for (ll i = 1; i < n; ++i) {
        ll a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }

    for (ll i = 1; i <= n; ++i) {
        dfs(i, -1, 0);
        cout << cost[i] << " ";
    }

    return 0;
}
