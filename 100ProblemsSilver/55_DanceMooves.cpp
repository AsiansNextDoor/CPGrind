#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

vector<int> parent(2e5);
vector<int> size(2e5);

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

signed main() {
    IOS;

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) make_set(i);

    vector<vector<int>> swaps(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> swaps[i][0] >> swaps[i][1];
        swaps[i][0]--, swaps[i][1]--;
    }

    vector<int> cows(n);
    iota(cows.begin(), cows.end(), 0);
    for (int i = 0; i < k; i++) {
        swap(cows[swaps[i][0]], cows[swaps[i][1]]);
    }
    
    map<int, set<int>> sets;
    for (int i = 0; i < n; i++) {
        union_sets(i, cows[i]);
        //cout << i << " " << cows[i] << endl;
    }
    for (int i = 0; i < n; i++) find_set(i);
    for (int i = 0; i < n; i++) sets[parent[i]].insert(i);

    iota(cows.begin(), cows.end(), 0);
    
    for (int i = 0; i < k; i++) {
        sets[parent[cows[swaps[i][0]]]].insert(swaps[i][1]);
        sets[parent[cows[swaps[i][1]]]].insert(swaps[i][0]);
        swap(cows[swaps[i][0]], cows[swaps[i][1]]);
    }
    
    //for (int i = 0; i < n; i++) cout << cows[i] << " "; 
    //cout << endl;
    for (int i = 0; i < n; i++) cout << sets[parent[i]].size() << endl;
}