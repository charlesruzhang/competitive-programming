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
    vvi facts(n + 1);
    for (int i = n; i >= 1; i--) {
    	for (int j = i; j <= n; j+=i) {
    		facts[j].push_back(i);
    	}
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
    	for (int f : facts[i]) {
    		int x = (i / f + 1) * f;
    		if (x <= n) {
    			ans += 1ll * (i / f + 1) * (i / f) * f;
    			break;
    		}
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
