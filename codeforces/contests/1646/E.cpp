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
const int LOG = 20;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<char> v(LOG * m);
    vector<ll> c(LOG);
    ll count = 0;
    for (int i = 1; i < LOG; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (!v[i * j]) {
    			v[i * j] = 1;
    			count ++;
    		}
    	}
    	c[i] = count;
    }
    ll ans = 1;
    vi visit(n+1);
    for (int i = 2; i <= n; i++) {
    	if (!visit[i]) {
    		ll cur = i;
    		int pow = 0;
    		while (cur <= n) {
    			visit[cur] = 1;
    			cur *= i;
    			pow++;
    		}
    		ans += c[pow];
    	}
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
