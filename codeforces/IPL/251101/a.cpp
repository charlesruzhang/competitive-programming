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
    int t, p;
    cin >> t >> p;
    if (p <= 20) {
    	double T = ((double) t) / (80 + (20 - p) * 2);
    	double ans = p * 2 * T;
    	cout << setprecision(10) << ans << endl;
    	return;
    }
    double T = ((double) t) / (100 - p);
    double ans = ((p - 20) + 40) * T;
    cout << setprecision(10) << ans << endl;
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
