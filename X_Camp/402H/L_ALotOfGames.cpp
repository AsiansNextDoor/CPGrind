#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int node = 0, r;
const int maxl = 1e5;
int trie[maxl][26];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (trie[cur][c]) cur = trie[cur][c];
        else {
            trie[cur][c] = ++node;
            cur = node;
        }
    }
}

int dfs(int cur) {
    map<int, int> m;
    int child = 0;
    int result = 0;
    for (char c = 0; c < 26; c++) {
        if (trie[cur][c]) {
            result |= !dfs(trie[cur][c]);
            child++;
        }
    }

    if (!child) return r;
    else return result;
}

signed main() {
    IOS;

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        add(s);
    }

    r = 1;
    int lastwin = dfs(0);
    r = 0;
    int lastlose = dfs(0);
    // cout << lastwin << " " << lastlose << endl;
    if (!lastwin) {
        if (lastlose) {
            if (k % 2) cout << "First" << endl;
            else cout << "Second" << endl;
        }
        else cout << "Second" << endl;
    }
    else {
        if (lastlose) {
            if (k % 2) cout << "Second" << endl;
            else cout << "First" << endl;
        }
        else cout << "Second" << endl;
    }
}