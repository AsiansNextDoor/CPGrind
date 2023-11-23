#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    vector<char> games;
    int h1 = 0, h2 = 0, p1 = 0, p2 = 0, s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        char g; cin >> g;
        games.push_back(g);
        if (g == 'H') {
            h2++;
        }
        else if (g == 'P') {
            p2++;
        }
        else {
            s2++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (games[i] == 'H') {
            h1++;
            h2--;
        }
        else if (games[i] == 'P') {
            p1++;
            p2--;
        }
        else {
            s1++;
            s2--;
        }
        
        ans = max(max(max(h1, p1), s1) + max(max(h2, p2), s2), ans);
    }
    
    cout << ans << endl;
}