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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (k == 4 ){
    	int tot = 0;
    	int toty = 0;
    	int maxx = 1000;
    	for (int i = 0; i < n; i++) {
    		if (a[i] % 4 == 0) {
    			cout << 0 << endl;
    			return;
    		}
    		if (a[i] % 4 == 3) {
    			maxx = 1;
    		} else if (a[i] % 4 == 2) {
    			tot++;
    		} else {
    			toty++;
    		}
    	}
    	if (tot < 2 && maxx == 1) {
    		cout << 1 << endl;
    	} else if (tot >= 2) {
    		cout << 0 << endl;
    	} else if (tot == 1 && toty > 0) {
    		cout << 1 << endl;
    	} else {
    		cout << 2 << endl;
    	}
    } else {
    	int ans = 5;
    	for (int i = 0; i < n; i++) {
    		int z = - a[i] % k;
    		if (z < 0) z += k;
    		ans = min(ans, z);
    	}
    	cout << ans << endl;
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
