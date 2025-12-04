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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int xx = 0;
    for (int i = 0; i < n; i++) {
    	xx += s[i] == '8' ? 1 : 0;
    }
    if (max(abs(x), abs(y)) <= n && abs(x) + abs(y) <= n + xx) {
    	cout << "Yes" << endl;
    } else {
    	cout << "no" << endl;
    }

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
