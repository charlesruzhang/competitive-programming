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
    int n, q;
    cin >> n >> q;
    vi cntr(n), cntc(n);
    for (int i = 1; i < n; i+=2) {
    	cntr[i] = cntc[i] = 1;
    }
    int r = n;
    int c = n;
    ll ans = 1ll * n * n;
    for (int i = 0; i < q; i++) {
    	string s;
    	cin >> s;
    	if (s == "ROW") {
    		int k;
    		cin >> k;
    		k--;
    		if (k && cntr[k] != cntr[k-1]) {
    			ans -= r;
    			c--;
    		} else if (k) {
    			ans += r;
    			c++;
    		}
    		if (k != n - 1 && cntr[k] != cntr[k+1]) {
    			ans -= r;
    			c--;
    		} else if (k != n - 1) {
    			ans += r;
    			c++;
    		}
    		cntr[k] ^= 1;
    	} else {
    		int k;
    		cin >> k;
    		k--;
    		if (k && cntc[k] != cntc[k-1]) {
    			ans -= c;
    			r--;
    		} else if (k) {
    			ans += c;
    			r++;
    		}
    		if (k != n - 1 && cntc[k] != cntc[k+1]) {
    			ans -= c;
    			r--;
    		} else if (k != n - 1) {
    			ans += c;
    			r++;
    		}
    		cntc[k] ^= 1;
    	}
    	cout << ans << endl;
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
