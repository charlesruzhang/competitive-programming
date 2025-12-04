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
    vi a(n-1), b(n);
    for (int i = 0; i < n - 1; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vi c(n);
    for (int i = 0; i < n - 1; i++) {
    	c[i] |= a[i];
    }
    for (int i = 1; i < n; i++) {
    	c[i] |= a[i-1];
    }
    for (int i = 0; i < n - 1; i++) {
    	if ((c[i] & c[i+1]) != a[i]) {
    		cout << -1 << endl;
    		return;
    	}
    }
    vector<pii> d(n);
    vi e(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 30; j >= 0; j--) {
    		if (c[i] & (1 << j)) {
    			if (!(b[i] & (1 << j))) {
    				break;
    			}
    		} else if (b[i] & (1 << j)) {
    			d[i].first |= (1 << j);
    		}
    	}
    	e[i] = d[i].first;
    	d[i].second = i;
    }
    // cout << "%%%%%%%%%%%" << endl;
    // for (int i = 0; i < n; i++) {
    // 	cout << e[i] << " ";
    // }
    // cout << endl;
    // cout << "------------" << endl;
    sort(d.begin(), d.end(), greater<>());
    for (int i = 0; i < n; i++) {
    	auto [x, y] = d[i];
    	int z = x | c[y];
    	//cout << x << " " << y << endl;
		int flag = 0;
		int last = 31;
		int cumm = 0;
		int tot = 0;
    	for (int j = 30; j >= 0; j--) {
    		if ((1 << j) & x) {
    			cumm |= (1 << j);
    			if ((y != n - 1 && ((1 << j) & e[y+1])) || (y && ((1 << j) & e[y-1]))) {
    				flag = 1;
    				break;
    			}
    		} else if (!(y != n - 1 && ((1 << j) & e[y+1])) && !(y && ((1 << j) & e[y-1]))) {
    			//cout << ">>> " << j << " " << e[y+1] << " " << (1 << j) << endl;
    			tot |= cumm;
    			last = j;
    		}
    	}
    	//cout << last << endl;
    	if (flag) x = (1 << last) | tot;
		e[y] = x;
    	//cout << x << " " << y << endl;
    } 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	//cout << (e[i] | c[i]) << " ";
    	ans += (e[i] | c[i]) - b[i];
    }
    // cout << endl;
    // for (int i = 0; i < n - 1; i++) {
    // 	cout << ((e[i] | c[i]) & (e[i+1] | c[i+1])) << " ";
    // }
    //cout << endl << endl;
    cout << ans << endl;
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
