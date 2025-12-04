// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    set<int> s1;
    set<int> s2;
    vector<string> vs(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vs[i] = s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                s1.insert(i + j);
                s2.insert(i - j);
                tot++;
            }
        }
    }
    if (s1.size() == 0 || s2.size() == 0) {
        cout << "YES" << endl;return;
    }
    if (s1.size() <= 2) {
        if (s1.size() == 1) {
            cout << "YES" << endl;
            return;
        }
        auto it = s1.begin();
        int x = *it;
        ++it;
        int y = *it;
        if (abs(y - x) == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    if (s2.size() <= 2) {
        if (s2.size() == 1) {
            cout << "YES" << endl;
            return;
        }
        auto it = s2.begin();
        int x = *it;
        ++it;
        int y = *it;
        if (abs(y - x) == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    char c = '#';
    if (tot == 4) {
        int flag = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (vs[i][j] == c && vs[i+1][j] == c && vs[i][j+1] == c && vs[i+1][j+1] == c) {
                    flag = 1;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
