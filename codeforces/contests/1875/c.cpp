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
    int n, m;
    cin >> n >> m;
    int g = gcd(n, m);
    n /= g;
    m /= g;
    if ((m & (m - 1)) != 0) {
    	cout << -1 << endl;
    	return;
    }
    ll tot = 0;
    ll acu = 1;
    while (m > 1) {
    	tot += acu * (m - 1);
    	n--;
    	int gg = gcd(n, m);
    	n /= gg;
    	m /= gg;
    	acu *= gg;
    }
    cout << tot * g << endl;
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
