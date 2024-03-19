#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    
    ll n, k; cin >> n >> k;
    vector<ll> cows(n);
    for (ll i = 0; i < n; i++) cin >> cows[i];

    multiset<pair<ll,ll>> s;
    for (ll i = 0; i < k; i++) s.insert({cows[i], i+1});

    vector<vector<ll>> adj(k+1); //adjacent farmers if they are able to choose at same time
    ll time, farmer;
    ll i = k;
    while (i < n) {
        time = (*s.begin()).f;
        farmer = (*s.begin()).s;
        s.insert({cows[i]+time, farmer});
        s.erase(s.begin());
        i++;
        while (time == (*s.begin()).f && i < n) {
            // cout << "i: " << i << endl;
            // cout << "farmers: " << (*s.begin()).s << endl;
            adj[farmer].push_back((*s.begin()).s);
            adj[(*s.begin()).s].push_back(farmer);
            s.insert({cows[i]+time, farmer});
            s.erase(s.begin());
            i++;
        }
    }

    time = (*s.begin()).f;
    cout << time << endl;

    queue<ll> bfs; bfs.push(farmer);
    vector<ll> visited(k+1, 0);
    while (!s.empty() && (*s.begin()).f == time){
        bfs.push((*s.begin()).s);
        visited[(*s.begin()).s] = 1;
        s.erase(s.begin());
    }
    
    // for (ll i = 1; i <= k; i++) {
    //     for (ll j: adj[i]) cout << j << " ";
    //     cout << endl;
    // }
    
    while (!bfs.empty()) {
        ll node = bfs.front(); bfs.pop();
        for (ll i: adj[node]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = 1;
            }
        }
    }
    
    for (ll i = 1; i <= k; i++) cout << visited[i];
}