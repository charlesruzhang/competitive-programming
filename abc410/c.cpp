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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = i + 1;
    }
    int idx = 0;
    while (q--) {
    	int x;
    	cin >> x;
    	if (x == 1) {
    		int p, y;
    		cin >> p >> y;
    		p--;
    		a[(p + idx) % n] = y;
    	} else if (x == 2) {
    		int p;
    		cin >> p;
    		p--;
    		cout << a[(p + idx) % n] << endl;
    	} else {
    		int k;
    		cin >> k;
    		idx += k;
    		idx = idx % n;
    	}
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
