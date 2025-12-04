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
    int n, m, q;
    cin >> n >> m >> q;
    m--;
    vi a(q);
    for (int i = 0; i < q; i++) {
    	cin >> a[i];
    	a[i]--;
    }
    int l = m;
    int r = m;
    int R = -1;
    int L = n;
    int flag = 1;
    for (int i = 0; i < q; i++) {
		if (R < a[i] && R >= 0 && (R + 1 < l || !flag)) {
			R++;
		}
		if (L > a[i] && L < n && (L - 1 > r || !flag)) {
			L--;
		}
    	if (a[i] < l) {
    		if (l - 1 > R && flag) l--;
    	} else if (a[i] > r) {
    		if (r + 1 < L && flag) r++;
    	} else {
    		if (l == r) {
    			flag = 0;
    			l++;
    		}
    		if (R == -1 && (l || !flag)) {
    			R = 0;
    		}
    		if (L == n && (r != n - 1 || !flag)) {
    			L = n - 1;
    		}
    	}
    	//cout << "! " << R << " " << l << " " << r << " " << L << endl;
    	cout << min(n, (r - l + 1) + (R + 1) + (n - L)) << " ";
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
