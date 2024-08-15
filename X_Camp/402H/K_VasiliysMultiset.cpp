#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll node = 0;
map<ll, ll> freq;
ll trie[6200000][2];

void add(ll x) {
    ll cur = 0;
    for (ll i = 31; i >= 0; i--) {
        ll bit = (x >> i) & 1;
        if (trie[cur][bit]) cur = trie[cur][bit];
        else {
            trie[cur][bit] = ++node;
            cur = node;
        }
        freq[cur]++;
    }
}

void remove(ll x) {
    ll cur = 0;
    for (ll i = 31; i >= 0; i--) {
        ll bit = (x >> i) & 1;
        cur = trie[cur][bit];
        freq[cur]--;
    }
}

void compute(ll x) {
    ll y = 0;
    ll cur = 0;
    for (ll i = 31; i >= 0; i--) {
        ll bit = (x >> i) & 1;
        y = (y << 1);
        if (trie[cur][!bit] && freq[trie[cur][!bit]]) {
            y += !bit;
            cur = trie[cur][!bit];
        }
        else {
            y += bit;
            cur = trie[cur][bit];
        }
    }

    cout << (x ^ y) << endl;
}

signed main() {
    IOS;

    ll q; cin >> q;

    add(0);
    while (q--) {
        char op; cin >> op;
        ll x; cin >> x;
        if (op == '+') add(x);
        else if (op == '-') remove(x);
        else compute(x);
    }
}