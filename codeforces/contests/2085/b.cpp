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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int b = 0;
    int l = n;
    int r = -1;
    for (int i = n-1; i >= 0; i --) {
    	if (!a[i]) {
    		b = 1;
    		l = min(l, i);
    		r = max(r, i);
    	}
    }
    if (!b) {
    	cout << 1 << endl;
    	cout << 1 << " " << n << endl;
    	return;
    }
    if (l != 0 || r != n - 1) {
    	if (l == r) {
    		if (l != 0) {
    			cout << 2 << endl;
    			cout << l << " " << l+1 << endl;
    			cout << 1 << " " << n-1 << endl;
    		} else {
    			cout << 2 << endl;
    			cout << 1 << " " << 2 << endl;
    			cout << 1 << " " << n-1 << endl;
    		}
    		return;
    	}
    	cout << 2 << endl;
    	cout << l+1 << " " << r+1 << endl;
    	cout << 1 << " " << n - (r - l) << endl;
    	return;
    }
    cout << 3 << endl;
    cout << 3 << " " << n << endl;
    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 2 << endl; 
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
