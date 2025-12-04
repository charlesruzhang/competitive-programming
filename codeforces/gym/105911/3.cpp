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
    int n, A, b, c;
    cin >> n >> A >> b >> c;
    vector<vector<int>> a(n, vi(6));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 6;j ++) {
    		cin >> a[i][j];
    	}
    }
    int maxx = 0;
    for (int i = 0; i < 3; i++) {
    	vector<pii> z;
    	for (int j = 0; j < n; j++) {
    		if (a[j][i] > a[j][i+3]) swap(a[j][i], a[j][i+3]);
    		z.push_back({a[j][i], 0});
    		z.push_back({a[j][i+3], 1});
    	}
    	sort(z.begin(), z.end());
    	int cur = 0;
    	for (int j = 0; j < 2 * n; j++) {
    		cur += (!z[j].second) ? 1 : -1;
    		maxx = max(maxx, cur);
    	}
    }
    cout << maxx << endl;
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
