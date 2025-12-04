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
void solve() {
    string s;
    string t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    map<char, int> ma;
    for (int i = 0; i < m; i++) {
        ma[t[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') {
            if (ma.find(s[i-1]) == ma.end()) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
