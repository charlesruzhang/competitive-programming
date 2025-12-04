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
    int n, m, L, x, y;
    cin >> n >> m >> L >> x >> y;
    vector<array<double, 3>> Q; 
    for (int i = 0; i < n; i++) {
    	int l, r;
    	cin >> l >> r;
    	Q.push_back({l, 0, (r - l) / (double)x + (L - r) / (double) y});
    }
    vector<double> ans(m);
    for (int i = 0; i < m; i++) {
    	int x;
    	cin >> x;
    	Q.push_back({x, 1, i});
    }
    sort(Q.begin(), Q.end());
    double best = 1e16;
    for (int i = 0; i < n + m; i++) {
    	auto [x, z, Y] = Q[i];
    	if (!z) {
    		best = min(best, Y);
    	} else {
    		ans[(int) Y] = min(best, (L - x) / (double) y);
    	}
    }
    for (int i = 0; i < m; i++) {
    	cout << setprecision(10) << ans[i] << endl;
    }
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
