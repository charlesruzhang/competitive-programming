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
    int n, m , q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vi(m));
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		if (s[j] == '*') {
    			a[i][j] = 1;
    			tot++;
    		}
    	}
    }
    int ptrx = tot % n;
    int ptry = tot / n;
    int rem = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < ptry; j++) {
    		if (a[i][j]) {
    			rem++;
    		}
    	}
    	if (i < ptrx && a[i][ptry]) {
    		rem++;
    	}
    }
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	if (a[x][y]) {
    		a[x][y] = 0;
    		if (y < ptry || (y == ptry && x < ptrx)) {
    			rem--;
    		}
    		tot--;
    		ptrx--;
    		if (ptrx < 0) {
    			ptrx = n - 1;
    			ptry--;
    		}
    		if (a[ptrx][ptry]) {
    			rem--;
    		}
    		cout << tot - rem << endl;
    	} else {
    		a[x][y] = 1;
    		if (y < ptry || (y == ptry && x < ptrx)) {
    			rem++;
    		}
    		tot++;
    		if (a[ptrx][ptry]) {
    			rem++;
    		}
    		ptrx++;
    		if (ptrx >= n) {
    			ptrx = 0;
    			ptry++;
    		}
    		cout << tot - rem << endl;
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
