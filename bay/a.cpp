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
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    ll ans = 0;
    ans += 1ll * a * b;
    while (a < n || b < m) {
    	if (b >= m) {
    		a++;
    	} else if (a >= n) {
    		b++;
    	} else if (a <= b) {
    		a++;
    	} else {
    		b++;
    	}
    	ans += 1ll * a * b;
    }
    cout << ans << endl;
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
