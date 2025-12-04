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
    cin >> s;
    int n = s.size() / 2;
    map<char, int> ma;
    map<char, int> m;
    map<char, int> m2;
    for (int i = 0; i < s.size(); i++) {
        ma[s[i]]++;
    }
    int t = 0;
    for (int i = 2 * n - 1; i >= n; i--) {
        if (s[i] != s[2*n - 1 - i]) {
            break;
        } else {
            t++;
        }
    }
    int a1 = 0;
    int a2 = 0;
    for (int i = 0; i < n; i++) {
        m[s[i]]++;
        if (m[s[i]] * 2 > ma[s[i]]) {
            a1 = 2 * n - i - t;
            break;
        }
    }
    for (int i = 2 * n-1; i >= n; i--) {
        m2[s[i]]++;
        if (m2[s[i]] * 2 > ma[s[i]]) {
            a2 = i + 1 - t;
            break;
        }
    }
    if (a1 != 0 || a2 != 0) {
        cout << min(a1, a2) << endl;
        return;
    }
    int tt = 0;
    for (int i = n; i < 2 *n; i++) {
        if (s[i] != s[2*n - 1 - i]) {
            break;
        } else {
            tt++;
        }
    }
    cout << n - min(n, t + tt) << endl;
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
