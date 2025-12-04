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
    mt19937 rng;
    int x, y, z, k;
    
    //cin >> x >> y >> z >> k;
    int l = 1;
    int r = 1e8;
    auto comp = [&] (int X) {
    	int t = X / k;
    	__int128 zp = z - (__int128)k * (t + 1) * t / 2;
    	ll cost = 1ll * X * x + 1ll * t * y;
    	if (zp < 0) {
    		return cost;
    	}
    	cost += 1ll * y * ((zp + X - 1) / X);
    	return cost;
    };
    while (l < r) {
    	int m1 = (l * 2 + r + 1) / 3;
    	int m2 = (l + r * 2 + 2) / 3;
    	ll c1 = comp(m1);
    	ll c2 = comp(m2);
    	if (c1 < c2) {
    		r = m2 - 1;
    	} else {
    		l = m1 + 1;
    	}
    }
    ll ans = comp(l);
    for (int i = l; i < l + 2e5; i++) {
    	ans = min(ans, comp(i));
    }
    for (int i = l - 1; i >= max(1, l - 200000); i--) {
    	ans = min(ans, comp(i));
    }
    cout << ans << " " << comp(l) << endl;
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
