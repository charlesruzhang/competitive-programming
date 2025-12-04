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
    int n, s, t;
    cin >> n >> s >> t;
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4; j++) {
    		cin >> v[i][j];
    	}
    }
    double ans = 1e18;
    for (int i = 0; i < (1 << n); i++) {
    	vi a(n);
    	for (int j = 0; j < n; j++) {
    		a[j] = j;
    	}
    	do {
    		double tot = 0;
    		int x = 0;
    		int y = 0;
    		for (int k = 0; k < n; k++) {
    			int j = a[k];
    			if (i & (1 << k)) {
    				tot += sqrt((double)((v[j][2] - x) * (v[j][2] - x) + (v[j][3] - y) * (v[j][3] - y))) / s;
    				tot += sqrt((double)((v[j][2] - v[j][0]) * (v[j][2] - v[j][0]) + (v[j][3] - v[j][1]) * (v[j][3] - v[j][1]))) / t;
    				x = v[j][0];
    				y = v[j][1];
    			} else {
    				tot += sqrt((double)((v[j][0] - x) * (v[j][0] - x) + (v[j][1] - y) * (v[j][1] - y))) / s;
    				tot += sqrt((double)((v[j][2] - v[j][0]) * (v[j][2] - v[j][0]) + (v[j][3] - v[j][1]) * (v[j][3] - v[j][1]))) / t;
    				x = v[j][2];
    				y = v[j][3];
    			}
    		}
    		ans = min(ans, tot);
    	} while (next_permutation(a.begin(), a.end()));
    }
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
