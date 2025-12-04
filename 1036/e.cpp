// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
    ll maxx = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	maxx = max(a[i], maxx);
    }
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    if (summ % 2 == 1 || maxx * 2 > summ) {
    	cout << -1 << endl;
    	return;
    }
    ll tot = 0;
    vvl b;
    int idx = 0;
    while (idx < 1) {
    	idx++;
    	for (int i = 0; i < n; i++) {
	    	tot += a[i];
	    	if (tot >= summ / 2) {
	    		vl c(n);
	    		ll diff = tot - summ / 2;
	    		ll diff2 = a[i] - diff;
	    		c[i] = abs(diff - diff2);
	    		ll rem = a[i] - c[i];
	    		ll tot2 = 0;
	    		if (diff < diff2) {
	    			for (int j = i - 1; j >= 0; j--) {
		    			tot2 += a[j];
		    			if (tot2 < rem / 2) {
		    				c[j] = 0;
		    			} else {
		    				c[j] = (tot2 - rem / 2);
		    				for (int k = j - 1; k >= 0; k--) {
		    					c[k] = a[k];
		    				}
		    				break;
		    			}
		    		}
		    		c[i] += diff;
		    		for (int j = i + 1; j < n; j++) {
		    			c[j] = a[j];
		    		}
	    		} else {
		    		tot2 = 0;
		    		for (int j = i + 1; j < n; j++) {
		    			tot2 += a[j];
		    			if (tot2 < rem / 2) {
		    				c[j] = 0;
		    			} else {
		    				c[j] = (tot2 - rem / 2);
		    				for (int k = j + 1; k < n; k++) {
		    					c[k] = a[k];
		    				}
		    				break;
		    			}
		    		}
		    		c[i] += diff2;
		    		for (int j = i - 1; j >= 0; j--) {
		    			c[j] = a[j];
		    		}
	    		}
	    		
	    		b.push_back(c);
	    		for (int j = 0; j < n; j++) {
	    			a[j] -= c[j];
	    			summ -= c[j];
	    			//cout << c[j] << " ";
	    		}
	    		//cout << endl;
	    		break;
	    	}
	    
	    }

    }
    int ix = -1;
    if (summ > 0) {
    	maxx = 0;
	    for (int i = 0; i < n; i++) {
	    	if (maxx < a[i]) { 
		    	maxx = max(maxx, a[i]);
		    	ix = i;
	    	}
	    }
	    vl c(n);
	    ll su = 0;
	    for (int i = 0; i < ix; i++) {
	    	c[i] = a[i];
	    	su += a[i];
	    }
	    c[ix] = su;
	    if (su) b.push_back(c);
	    summ -= 2 * su;
    }
    if (summ > 0) {
    	ll su = 0;
	    vl d(n);
	    for (int i = ix + 1; i < n; i++) {
	    	d[i] = a[i];
	    	su += a[i];
	    }
	    d[ix] = su;
	    if (su) b.push_back(d);
    }
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
    	for (int j = 0; j < n; j++) {
    		cout << b[i][j] << " ";
    	}
    	cout << endl;
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
