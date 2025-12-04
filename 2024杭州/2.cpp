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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n * m);
    for (int i = 0; i < n * m; i++) {
    	cin >> a[i];
    	a[i]--;
    }
    if (k >= m) {
    	cout << m << endl;
    	return;
    }
    vi cnt(n);
    for (int i = 0; i < n * m; i++) {
    	cnt[a[i] / m] ++;
    	if (cnt[a[i] / m] >= m - k) {
    		cout << max(m, i + 1) << endl;
    		return;
    	}
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
