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
void solve() {
    int n, m;
    cin >> n >> m;
    if (m > 2 * n - 1) {
    	cout << "No" << endl;
    	return;
    }
    cout << "Yes" << endl;
    vvi ans(m, vi(2 * n));
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		ans[i][(2 * j + i) % (2 * n)] = ans[i][(2 * j + i + 1) % (2 * n)] = j + 1; 
    	}
    }
    for (int j = 0; j < 2 * n; j++) {
    	for (int i = 0; i < m; i++) {
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
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
