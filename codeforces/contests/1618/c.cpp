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
void solve() {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll G = 0;
    ll H = 0;
    for (int i = 0; i < n; i++) {
    	if (i % 2) {
    		H = gcd(H, a[i]);
    	} else {
    		G = gcd(G, a[i]);
    	}
    }
    int f = 1, g = 1;
    for (int i = 0; i < n; i++) {
    	if (i % 2) {
    		if (a[i] % G == 0) {
    			f = 0;
    		}
    	} else {
    		if (a[i] % H == 0) {
    			g = 0;
    		}
    	}
    }
    if (f ) {
    	cout << G << endl;
    } else if (g) {
    	cout << H << endl;
    } else {
    	cout << 0 << endl;
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
