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
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	a[i] = cur;
    	cur++;
    	if (cur == k) cur -= k;
    }
    vi mark(n), mark2(n);
    for (int i = 0; i < q; i++) {
    	int c, l, r;
    	cin >> c >> l >> r;
    	l--; r--;
    	if (c == 2) {
    		for (int j = l; j <= r; j++) {
    			mark[j] = 1;
    		}
    	} else {
    		for (int j = l; j <= r; j++) {
    			mark2[j] = 1;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (mark2[i] && !mark[i]) {
    		a[i] = k;
    	} 
    	if (mark2[i] && mark[i]) {
    		a[i] = k + 1;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
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
