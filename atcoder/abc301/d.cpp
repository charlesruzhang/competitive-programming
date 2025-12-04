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
    string s;
    cin >> s;
    ll n;
    cin >> n;
    int m = s.size();
    for (int i = m - 1; i >= 0; i--) {
    	if (s[i] != '?') {
    		int z = m - 1 - i;
    		int d = s[i] - '0';
    		n -= d * (1ll << z);
    	}
    }
    if (n < 0) {
    	cout << -1 << endl;
    	return;
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
    	int z = m - 1 - i;
    	if (s[i] == '?') {
    		if ((1ll << z) > n) {
    			continue;
    		} else {
    			n -= 1ll << z;
    			ans += (1ll << z);
    		}
    	} else {
    		int d = s[i] - '0';
    		ans += d * (1ll << z);
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
