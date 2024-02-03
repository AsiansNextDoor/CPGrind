#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int a, b, t;
vector<int> x, y;
vector<pair<int,int>> books;

bool check(int time) {
    priority_queue<int> pq;
    int i = 0, ind = 0;
    for (i = 0; i < a; i++) {
        int worm = x[i];
        while (ind < t && worm > books[ind].f) {
            pq.push(books[ind].s);
            ind++;
        }
        int j = time;
        while (j-- && !pq.empty()) {
            pq.pop();
        }
    }

    for (ind; ind < t; ind++) pq.push(books[ind].s);

    i = 0;
    while (i < b && !pq.empty()) {
        int j = time;
        while (j-- && !pq.empty()) {
            int book = pq.top(); pq.pop();
            if (book >= y[i]) return false;
        }
        i++;
    }

    if (!pq.empty()) return false;
    return true;
}

signed main() {
    IOS;

    cin >> a >> b >> t;
    x.resize(a), y.resize(b);
    for (int i = 0; i < a; i++) cin >> x[i];
    for (int i = 0; i < b; i++) cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.rbegin(), y.rend());

    books.resize(t);
    for (int i = 0; i < t; i++) cin >> books[i].f >> books[i].s;
    sort(books.begin(), books.end());

    int l = 1, r = t, ans = -1; //000001111 --> first 1
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        //cout << "mid: " << mid << endl;
        if (check(mid)) {
            //cout << "True" << endl;
            ans = mid;
            r = mid - 1;
        }
        else {
            //cout << "False" << endl;
            l = mid + 1;
        }
    }

    cout << ans << endl;
}