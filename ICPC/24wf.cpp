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
    vvi a(n, vi(k));
    map<int, int> ma;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < k; j++) {
	    	cin >> a[i][j];
	    	ma[a[i][j]] = i;
	    	cnt[a[i][j]] ++;
    	}
    }
    int z = n * k;
    vi ans(n);
    for (auto [x, y] : ma) {
    	ans[y]+=cnt[x];
    }
    for (int i = 0; i < n; i++) {
    	cout << setprecision(10) << ans[i] / (long double) z << endl;
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
