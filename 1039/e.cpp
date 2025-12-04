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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int l = 0;
    int r = n;
    vector<pii> ans(n+1);
    auto check = [&] (int m) {
    	vi P(n), maxx(n+1, 0), idx(n+1, -1);
    	for (int i = 0; i < n; i++) {
    		P[i] = (a[i] >= m) ? 1 : -1;
    	}
    	int cur = 0;
    	for (int i = 0; i < n; i++) {
    		cur += P[i];
    		if (maxx[i] > cur) {
    			idx[i+1] = i;
    			maxx[i+1] = cur;
    		} else {
    			idx[i+1] = idx[i];
    			maxx[i+1] = maxx[i];
    		}
    		if (i + 1 >= k) {
    			if (cur - maxx[i+1-k] > 0) {
    				ans[m] = {idx[i+1-k] + 1, i};
    				return true;
    			}
    		}
    	}
    	return false;
    };
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    cout << l << endl;
    //cout << l << " " << ans[l].first + 1 << " " << ans[l].second + 1 << endl;
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
