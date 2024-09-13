//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

struct node {
    node *start, *end; // start and end of basket
    node() : start(nullptr), end(nullptr) {}
};

int blobs = 0;
map<int, int> exist;
map<int, node*> nodes;
map<node*, int> indexes;

void merge(int i) {
    node* n1 = new node();
    n1->start = n1;
    n1->end = n1;

    exist[i]++;
    nodes[i] = n1;
    indexes[n1] = i;
    int starti, endi;
    if (exist[i - 1] && exist[i + 1]) {
        nodes[i - 1]->start->end = nodes[i + 1]->end;
        nodes[i + 1]->end->start = nodes[i - 1]->start;
        nodes[i]->start = nodes[i - 1]->start;
        nodes[i]->end = nodes[i + 1]->end;
    }
    else if (exist[i - 1]) {
        nodes[i - 1]->start->end = nodes[i];
        nodes[i]->start = nodes[i - 1]->start;
    }
    else if (exist[i + 1]) {
        nodes[i + 1]->end->start = nodes[i];
        nodes[i]->end = nodes[i + 1]->end;
    }
    starti = indexes[nodes[i]->start];
    endi = indexes[nodes[i]->end];
    blobs = max(endi - starti + 1, blobs);
}


signed main() {
    IOS;
    
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int n, b; cin >> n >> b;

    vector<int> snow(n);
    for (int i = 0; i < n; i++) cin >> snow[i];

    vector<vector<int>> boots(b, vector<int>(3));
    for (int i = 0; i < b; i++) {
        cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }


    vector<vector<int>> si(n);
    for (int i = 0; i < n; i++) si[i] = {snow[i], i};
    
    sort(boots.rbegin(), boots.rend());
    sort(si.rbegin(), si.rend());

    int j = 0;
    vector<int> ans(b, 0);
    for (int i = 0; i < b; i++) {
        int curd = boots[i][0], curs = boots[i][1], curi = boots[i][2];
        while (j < n && si[j][0] > curd) {
            merge(si[j][1]);
            j++;
        }

        if (curs > blobs) ans[curi]++;
    }

    for (int i = 0; i < b; i++) cout << ans[i] << endl;
}