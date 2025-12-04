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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if (a < b) swap(a, b);
    if (c < d) swap(c, d);
    if (a - 2 > 2 * b || c - 2 > 2 * d) {
    	cout << "no" << endl;
    } else {
    	cout << "yes" << endl;
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
