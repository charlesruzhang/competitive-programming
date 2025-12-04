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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vi cnt(n * m + 1);
    vector<pii> v;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    		cnt[a[i][j]]++;
    		v.push_back({a[i][j], i * m + j});
    	}
    }
    for (int i = 1; i <= n * m; i++) {
    	if (cnt[i] > n * m / 2) {
    		cout << "-1" << endl;
    		return;
    	}
    }
    sort(v.begin(), v.end(), greater<>());
    vi s(n * m);
    for (int i = 0; i < n * m; i++) {
    	s[v[i].second] = i;
    }
    vvi ans(n, vi(m));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		ans[i][j] = v[(s[i * m + j] + n * m / 2) % (n * m)].first;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
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
