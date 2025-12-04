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
    ll maxx = 0;
    int idx = 1;
    for (int k = 2; k <= m; k++) {
    	int g = gcd(n, k);
    	int ma = n / g;
    	ll ans = 0;
    	for (int t = 0; t < k / g; t++) {
    		ll l = (1ll * t * n + 1 + k - 2) / (k - 1); 
    		ll r = (1ll * t * n + n) / k;
    		int start = (l * k - 1) % n + 1;
    		int end = (r * k - 1) % n + 1;
    		int cnt = r - l + 1;
    		ans += 1ll * (start + end) * cnt / 2;
    	}
    	//cout << ans << " ! " << k << endl;
    	if (maxx < ans) {
    		maxx = ans;
    		idx = k;
    	}
    }
    //cout << maxx << endl;
    cout << idx << endl;
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
