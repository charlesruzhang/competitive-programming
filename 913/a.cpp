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
    int R, y, d, w;
    cin >> R >> y >> d >> w;
    ld ans = 0;
    for (int i = 0; i <= y; i++) {
    	for (int j = 0; j <= y; j++) {
    		ld td = 0;
    		ld cur = 0;
    		int flag = 1;
    		for (int z = 0; z < y; z++) {
    			if (z < i) {
    				td -= d;
    				cur += d;
    			}
    			cur *= (1 + R / 100.0);
    			if (z >= j) {
    				if (cur < w) {
    					flag = 0;
    					break;
    				}
    				cur -= w;
    				td += w;
    			}
    		}
    		if (flag) ans = max(ans, td);
    	}
    }
    for (int i = 0; i <= y; i++) {
		double l = 0;
		double r = w;
		while (l + 1e-6 < r) {
			double m = (l + r) / 2;
	    	ld td = 0;
			ld cur = 0;
			int flag = 1;
			for (int z = 0; z < y; z++) {
				if (z < i) {
					td -= d;
					cur += d;
				}
				cur *= (1 + R / 100.0);
				//cout << "z = " << z << " " << cur << " " << r << endl;
				if (z == i - 1) {
					if (cur < m) {
						flag = 0;
						break;
					}
					cur -= m;
					td += m;
				}
				if (z >= i) {
					if (cur < w) {
						flag = 0;
						break;
					}
					cur -= w;
					td += w;
				}
			}
	    	if (flag) ans = max(ans, td);
	    	if (flag) {
	    		l = m;
	    	} else {
	    		r = m;
	    	}
		}
    }
    for (int i = 0; i <= y; i++) {
		double l = 0;
		double r = d;
		while (l + 1e-6 < r) {
			double m = (l + r) / 2;
			//cout << i << " " << m << endl;
	    	ld td = 0;
			ld cur = 0;
			int flag = 1;
			for (int z = 0; z < y; z++) {
				if (z < i) {
					td -= d;
					cur += d;
				}
				if (z == i) {
					td -= m;
					cur += m;
				}
				cur *= (1 + R / 100.0);
				if (z >= i) {
					if (cur < w) {
						flag = 0;
						break;
					}
					cur -= w;
					td += w;
				}
			}
	    	if (flag) ans = max(ans, td);
	    	if (flag) {
	    		r = m;
	    	} else {
	    		l = m;
	    	}
		}
		
    }
    cout << setprecision(10) << ans << endl;
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
