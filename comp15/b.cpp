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
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    int m;
    cin >> m;
    vi c(m), d(m);
    for (int i = 0; i < m; i++) {
    	cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> d[i];
    }
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
    	ma[a[i]] = b[i];
    }
    for (int i = 0; i < m; i++) {
    	if (ma[c[i]] < d[i]) {
    		cout << 0 << endl;
    		return;
    	}
    	ma[c[i]]-=d[i];
    }
    auto it = ma.begin();
    ll ans = 1;
    while (it != ma.end()) {
    	if (it -> second != 0) {
    		ans = (ans * 2) % MOD;
    	}
    	++it;
    }
    cout << ans << endl;
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
