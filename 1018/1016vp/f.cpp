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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    vvi same(m, vi(n));
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		string t;
    		cin >> t;
    		if (t == s[j]) {
    			same[i][j] = 1;
    		}
    	}
    }
    int tot = 0;
    ll ans = 0;
    vi mark(n);
	int maxx = 0;
	int maxi = -1;
	vector<int> cur(m);
	for (int j = 0; j < n; j++) {
		if (mark[j]) continue;
		for (int i = 0; i < m; i++) {
			if (same[i][j]) cur[i]++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (maxx < cur[i]) {
			maxx = cur[i];
			maxi = i;
		}
	}
	if (maxx == 0) {
		cout << -1 << endl;
		return;
	}
	ans += n;
	for (int i = 0; i < n; i++) {
		if (same[maxi][i]) mark[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			int flag = 0;
			for (int j = 0; j < m; j++) {
				if (same[j][i]) flag = 1;
			}
			if (!flag) {
				cout << -1 << endl;
				return;
			}
		} 
	}
	cout << ans + 2 * (n - maxx) << endl;
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
