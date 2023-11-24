#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b; cin >> n >> b;
    
    vector<int> snow;
    int dp[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        int f; cin >> f;
        snow.push_back(f);
        
        dp[i] = n;
        visited[i] = false;
    }
    
    vector<pair<int ,int>> boots;
    for (int i = 0; i < b; i++) {
        int s, d; cin >> s >> d;
        boots.push_back({s, d});
    }
    
    dp[0] = 0;
    visited[0] = true;
    for (int i = 0; i < b; i++) {
        int s = boots[i].first, d = boots[i].second;
        
        int steps = d;
        for (int j = 1; j < n; j++) {
            steps--;
            if (!visited[j]) {
                if (s >= snow[j] && steps >= 0) {
                    steps = d;
                    dp[j] = min(i, dp[j]);
                    visited[j] = true;
                }
            }
            else {
                if (s >= snow[j]) {
                    steps = d;
                }
            }
        }
    }
    
    cout << dp[n-1] << endl;
}
