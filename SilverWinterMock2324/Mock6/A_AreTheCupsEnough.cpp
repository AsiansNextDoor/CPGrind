#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int main() {
    IOS;

    int m, n; cin >> m >> n;
    vector<int> cups(n);
    for (int i = 0; i < n; i++) cin >> cups[i];

    int k = 0;
    set<int> s1;
    set<int> s2;
    map<int,int> m1;
    map<int,int> m2;
    for (int i = 0; i < n/2; i++) {
        m2[cups[i*2]]++;
        if (m2[cups[i*2]] == 1) s2.insert(cups[i*2]);
        m2[cups[i*2+1]]++;
        if (m2[cups[i*2+1]] == 1) s2.insert(cups[i*2+1]);
        m2[cups[i]]--;
        if (m2[cups[i]] == 0) s2.erase(s2.find(cups[i]));
        m1[cups[i]]++;
        if (m1[cups[i]] == 1) s1.insert(cups[i]);

        bool valid = true;
        auto it2 = s2.begin();
        int cur1 = 0, cur2 = m2[*it2];
        for (auto it1 = s1.begin(); it1 != s1.end(); it1++) {
            if (*it1 >= *it2) {
                valid = false;
                break;
            }
            cur1 = m1[*it1];
            while (true) {
                if (cur1 > cur2) {
                    cur1 -= cur2;
                    it2++;
                    cur2 = m2[*it2];
                }
                else if (cur1 < cur2) {
                    cur2 -= cur1;
                    break;
                }
                else {
                    it2++;
                    cur2 = m2[*it2];
                    break;
                }
            }
        }

        if (valid) k = i+1;
    }

    cout << k << endl;
}