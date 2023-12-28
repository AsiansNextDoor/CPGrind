#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 200;
    }

    vector<int> b = {-1}, c;
    int cnt;
    set<int> ans;
    if (n > 8) n = 8;
    for (int i = 1; i < (1 << n); i++) {
        int count = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if ((i >> j & 1)) {
                count += a[j];
                temp.push_back(j+1);
            }
        }
        count %= 200;

        if (ans.find(count) == ans.end()) {
            ans.insert(count);
        }
        else {
            cnt = count;
            b = temp;
            break;
        }
    }

    if (b[0] == -1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < (1 << n); i++) {
        int count = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if ((i >> j & 1)) {
                count += a[j];
                temp.push_back(j+1);
            }
        }
        count %= 200;

        if (count == cnt) {
            c = temp;
            break;
        }
    }

    cout << "Yes" << endl;
    cout << b.size() << " ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl << c.size() << " ";
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}