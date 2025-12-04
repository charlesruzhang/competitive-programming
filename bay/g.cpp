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
    map<ll, int> ma;
    int z = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	ll cur = 0;
    	for (int j = 0; j < m; j++) {
    		string s;
    		cin >> s;
    		for (int k = 0; k < m; k++) {
    			cur = cur * 2 + (s[k] == '.' ? 0 : 1);
    		}
    	}
    	if (cur == 0) {
    		z++;
    	} else {
    		ma[cur]++;
    	}
    }

    for (auto [x, y]: ma) {
    	ans += 1ll * y * (y - 1) / 2;
    }
    ans += 1ll * z * (n - 1) - 1ll * z * (z - 1) / 2;
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
