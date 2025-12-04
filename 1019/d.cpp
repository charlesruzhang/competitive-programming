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
    	if (a[i] == -1) {
    		a[i] = n+5;
    	}
    }
    int curs = n;
    int curt = 1;
    vi ans(n);
    int tot = 0;
    for (int i = 1; i <= 100; i++) {
    	int l = 0;
    	int r = n - 1;
    	while (l <= r) {
    		while (a[l] <= i && l <= r) {
    			if (a[l] == i) {
	    			if (i % 2) {
		    			ans[l] = curs--;
		    			tot++;
	    			} else {
	    				ans[l] = curt++;
		    			tot++;
	    			}
    			}
    			l++;
    			if (l > r) break;
    		} 
    		while (a[r] <= i && l <= r) {
    			if (a[r] == i) {
	    			if (i % 2) {
		    			ans[r] = curs--;
		    			tot++;
	    			} else {
	    				ans[r] = curt++;
		    			tot++;
	    			}
	    		}
    			r--;
    		}
    		if (l > r) break;
    		l++;
    		r--;
    	}
    	if (tot == n - 1) {
    		break;
    	}
	}
	for (int i = 0; i < n; i++) {
		if (!ans[i]) {
			ans[i] = curs;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
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
