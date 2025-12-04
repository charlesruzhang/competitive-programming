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
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    ll maxx = *max_element(a.begin(), a.end());
    if (summ % 2 == 1 || maxx * 2 > summ) {
    	cout << -1 << endl;
    	return;
    }
    vvl b;
    ll tot = 0;
    vl c(n);
    for (int i = 0; i < n; i++) {
    	tot += a[i];
    	if (2 * tot >= summ) {
    		tot -= a[i];
    		ll uot = summ - tot - a[i];
    		ll target = 0;
			for (int j = 0; j < n; j++) {
				if (j != i) c[j] = a[j];
			}
    		if (tot < uot) {
    			c[i] = (a[i] + uot - tot) / 2;
    			target = c[i] - (uot - tot);
    			for (int j = i - 1; j >= 0; j--) {
    				target -= a[j];
    				if (target >= 0) c[j] = 0;
    				else {
    					c[j] = -target;
    					break;
    				}
    			}
    		} else {
    			c[i] = (a[i] + tot - uot) / 2;
    			target = c[i] - (tot - uot);
    			for (int j = i + 1; j < n; j++) {
    				target -= a[j];
    				if (target >= 0) c[j] = 0;
    				else {
    					c[j] = -target;
    					break;
    				}
    			}
    		}
    		break;
    	}
    }
    vl d(n);
    int f = 0;
    for (int i = 0; i < n; i++) {
    	d[i] = a[i] - c[i];
    	if (d[i]) f = 1;
    }
    b.push_back(c);
    if (f) b.push_back(d);
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
