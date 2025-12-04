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
    int m;
    cin >> m;
    vl cnt(m), l(m), r(m);
    map<ll, vector<pll>> ma;
    __int128 L = 0;
    __int128 R = 0;
    vl C(m);
    for (int i = 0; i < m; i++) {
    	cin >> cnt[i] >> l[i] >> r[i];
    	vl a(cnt[i]);
    	vl c(cnt[i]);
    	L += l[i];
    	R += r[i];
    	for (int j = 0; j < cnt[i]; j++) {
    		cin >> a[j];
    	}
    	for (int j = 0; j < cnt[i]; j++) {
    		cin >> c[j];
    		C[i] += c[j];
    		ma[a[j]].push_back({i, c[j]});
    	}
    }
    if (R - L > 1e5) {
    	cout << 0 << endl;
    	return;
    }
    ll ans = 1e18;
    for (ll i = L; i <= R; i++) {
    	auto& ref = ma[i];
    	if (ref.size() == 0) {
    		cout << 0 << endl;
    		return;
    	}
    	ll tot = R;
    	ll copy = 0;
    	for (int j = 0; j < ref.size(); j++) {
    		auto [idx, c] = ref[j];
    		ll sz = max(l[idx], C[idx] - c);
    		copy += max(0ll, sz - (C[idx] - c));
    		tot += sz - r[idx];
    	}
    	copy += max(0ll, i - tot);
    	ans = min(ans, copy);
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
