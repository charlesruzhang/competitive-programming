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
    int h, d;
    cin >> h >> d;
    ll ans = 0;
    if (h == 1) {
    	ans++;
    	h = 2;
    }
    int l = 0;
    int r = d;
    while (l < r) {
    	int m = (l + r) / 2;
    	int rem = d % (m + 1);
    	int di = d / (m + 1);
    	int x = m + 1 - rem;
    	ll tot = 1ll * rem * (di + 2) * (di + 1) / 2 + 1ll * x * (di + 1) * di / 2 - m;
    	if (tot >= h) {
    		l = m + 1;
    	} else {
    		r = m;
    	}
    } 
    cout << ans + d + l << endl;
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
