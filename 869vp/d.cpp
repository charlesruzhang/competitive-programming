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
    if (k <= (n - 1) / 2) {
    	int tot = (n - 1) / 2 - k;
    	for (int i = 0; i < tot; i++) {
    		cout << "DRUR";
    	}
    	cout << "DL" << endl;
    	return;
    } else {
    	int tot = k - (n - 1) / 2;
    	for (int i = 0; i < tot; i++) {
    		cout << "DLUL";
    	}
    	cout << "DLUL";
    	if (k == n - 2) {
    		cout << "DRDL" << endl;
    		return;
    	} else if (k == n - 3) {
    		cout << "DRDL";
    		for (int i = 0; i < n; i++) {
    			cout << "DLUL";
    		}
    		cout << "RDL" << endl;
    		return;
    	} else {
	    	for (int i = 0; i < n; i++) {
	    		cout << "DRUR";
	    	}
	    	cout << "LURDL" << endl;
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
