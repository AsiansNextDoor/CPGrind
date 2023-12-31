#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t; cin >> s >> t;

    map<char,int> ms;
    map<char,int> mt;
    for (int i = 0; i < s.size(); i++) ms[s[i]]++;
    for (int i = 0; i < t.size(); i++) mt[t[i]]++;

    set<char> exclude;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (ms[s[i]] == mt[s[i]]) {
            temp += s[i];
        }
        else {
            exclude.insert(s[i]);
        }
    }
    s = temp;
    temp.clear();

    for (int i = 0; i < t.size(); i++) {
        if (ms[t[i]] == mt[t[i]]) {
            temp += s[i];
        }
    }
    t = temp;

    
    int q; cin >> q;

    while (q--) {
        string d; cin >> d;

        
    }
}#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t; cin >> s >> t;

    map<char,int> ms;
    map<char,int> mt;
    for (int i = 0; i < s.size(); i++) ms[s[i]]++;
    for (int i = 0; i < t.size(); i++) mt[t[i]]++;

    set<char> exclude;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (ms[s[i]] == mt[s[i]]) {
            temp += s[i];
        }
        else {
            exclude.insert(s[i]);
        }
    }
    s = temp;
    temp.clear();

    for (int i = 0; i < t.size(); i++) {
        if (ms[t[i]] == mt[t[i]]) {
            temp += s[i];
        }
    }
    t = temp;

    
    int q; cin >> q;

    while (q--) {
        string d; cin >> d;

        
    }
}