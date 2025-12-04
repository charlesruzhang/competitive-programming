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
    if (n == 1) {
    	for (int i = 0; i < q; i++) {
    		int x;
    		cin >> x;
    		cout << ((i + 1) % 2) << endl;
    	}
    	return;
    }
    vi a(q);
    vi c(n);
    int cnt = 0;
    for (int i = 0; i < q; i++) {
    	cin >> a[i];
    	a[i]--;
    	int z = a[i];
    	if (c[z] && z != n - 1 && z != 0 && c[z-1] == 1 && c[z+1] == 1) {
    		cnt++;
    	}
		if (c[z] && z != n - 1 && z != 0 && c[z-1] == 0 && c[z+1] == 0) {
    		cnt--;
    	}
    	if (c[z] && z == 0 && c[z+1] == 0) {
    		cnt--;
    	}
    	if (c[z] && z == n-1 && c[z-1] == 0) {
    		cnt--;
    	}
    	c[z] = 1 - c[z];
    	if (c[z] && z != n - 1 && z != 0 && c[z-1] == 1 && c[z+1] == 1) {
    		cnt--;
    	}
		if (c[z] && z != n - 1 && z != 0 && c[z-1] == 0 && c[z+1] == 0) {
    		cnt++;
    	}
    	if (c[z] && z == 0 && c[z+1] == 0) {
    		cnt++;
    	}
    	if (c[z] && z == n-1 && c[z-1] == 0) {
    		cnt++;
    	}
    	cout << cnt << endl;
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
