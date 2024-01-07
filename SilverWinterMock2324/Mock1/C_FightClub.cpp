#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    ll n, q; cin >> n >> q;
    vector<vector<ll>> adj(n+1);
    vector<ll> grid(n+1, -1);

    ll time = 0;
    while (q--) {
        char type;
        ll a, b;
        cin >> type >> a >> b;
        if (type == 'A') {
            if (grid[a] == -1) {
                if (grid[b] == -1) {
                    grid[a] = time;
                    grid[b] = time + 1;
                }
                else {
                    grid[a] = grid[b] + 1;
                }
            }
            else {
                if (grid[b] == -1) {
                    grid[b] = grid[a] + 1;
                }
                else {
                    if (grid[a] > grid[b]) swap(a, b);
                    vector<ll> visited(n+1, 0);
                    grid[b] = grid[a];
                    queue<pair<ll,ll>> bfs; bfs.push({b, b});
                    visited[b] = 1;
                    while (!bfs.empty()) {
                        ll node = bfs.front().f, parent = bfs.front().s; bfs.pop();
                        grid[node] = grid[parent]+1;
                        for (ll i: adj[node]) {
                            if (!visited[i]) {
                                bfs.push({i, node});
                                visited[i]++;
                            }
                        }
                    }
                }
            }
        }
        else if (type == 'R') {
            if (grid[a] == -1) {
                grid[a] = time;
                grid[b] = time;
            }
            else {
                if (grid[b] == -1) {
                    grid[b] = grid[a];
                }
                else {
                    if (grid[a] > grid[b]) swap(a, b);
                    vector<ll> visited(n+1, 0);
                    grid[b] = grid[a] - 1;
                    queue<pair<ll,ll>> bfs; bfs.push({b, b});
                    visited[b] = 1;
                    while (!bfs.empty()) {
                        ll node = bfs.front().f, parent = bfs.front().s; bfs.pop();
                        grid[node] = grid[parent]+1;
                        for (ll i: adj[node]) {
                            if (!visited[i]) {
                                bfs.push({i, node});
                                visited[i]++;
                            }
                        }
                    }
                }
            }
        }
        else {
            if (grid[a] == -1 || grid[b] == -1 || ((abs(grid[a]-grid[b]) >= 100000))) cout << "?" << endl;
            else if ((grid[a] % 2) == (grid[b] % 2)) cout << "R" << endl;
            else cout << "A" << endl;
            continue;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
        time += 100000;
    }
}