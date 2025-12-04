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
    int n;
    cin >> n;
    vi a(n);
    vi v(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	v[a[i]] = i;
    }
    vi mark(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
    	mark[v[i]] = 1;
    	int l = 0, r = 0;
    	for (int j = 0; j < v[i]; j++) {
    		l += 1 - mark[j];
    	}
    	for (int j = v[i] + 1; j < n; j++) {
    		r += 1 - mark[j];
    	}
    	ans += min(l, r);
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
