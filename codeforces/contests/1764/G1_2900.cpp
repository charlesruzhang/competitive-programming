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
int query(int l, int r, int k) {
	if (l == r) return 1;
	cout << "? " << l << " " << r << " " << k << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    int z = 0;
    int side = 0;
    vi left(n+2);
    vi right(n+2);
    right[1] = n / 2 + 1;
    left[n] = n / 2 + 1;
    function <bool(int)> check = [&] (int m) {
    	int a = query(1, m, 2);
    	left[m] = a;
    	int b = query(m + 1, n, 2);
    	right[m+1] = b;
    	int u = m - (m - a) * 2;
    	int v = (n - m) - (n - m - b) * 2;
    	if (!z && u == v) {
    		assert(n % 2 == 0);
    		if (m != 1) {
	    		int res = query(1, m, n);
	    		if (res == 2) {
	    			side = 1;
	    		} else {
	    			side = 0;
	    		}
    		} else {
				int res = query(m+1, n, n);
	    		if (res == 2) {
	    			side = 0;
	    		} else {
	    			side = 1;
	    		}
    		}
    		z = 1;
    		if (side) return false;
    		else return true;
    	} else if (u > v) {
    		return true;
    	} else if (u < v) {
    		return false;
    	} else {
    		if (side) return false;
    		else return true;
    	}
    };
    while (l < r) {
    	int m = (l + r) / 2;
    	if (r - l == 1) {
    		if (!z && n % 2 == 0) {
    			if (l != 1) {
    				int res = query(1, l, n);
    				if (res != 1) {
    					cout << "! " << r << endl;
    					return;
    				} else {
    					cout << "! " << l << endl;
    					return;
    				}
    			} else {
    				int res = query(r, n, n);
    				if (res != 1) {
    					cout << "! " << l << endl;
    					return;
    				} else {
    					cout << "! " << r << endl;
    					return;
    				}
    			}
    		}
    		if (r != n) assert(left[r]);
    		if (l != 1) assert(left[l-1]);
    		if (l != 1) assert(right[l]);
    		if (r != n) assert(right[r+1]);
    		int diff1 = left[r] - left[l-1];
    		int diff2 = right[l] - right[r+1];
    		assert(!(diff1 == 2 && diff2 == 2));
    		assert(diff1 * diff2 == 2);
    		if (diff1 == 1) {
    			int res = query(1, l, 2);
    			if (res == left[l-1]) {
    				cout << "! " << r << endl;
    				return;
    			} else {
    				cout << "! " << l << endl;
    			}
    		} else {
    			int res = query(r, n, 2);
    			if (res == right[r+1]) {
    				cout << "! " << l << endl;
    				return;
    			} else {
    				cout << "! " << r << endl;
    			}
    		}
    	}
    	if (check(m)) {
    		r = m;
    	} else {
    		l = m + 1;
    	}
    }
    cout << "! " << l << endl;
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
