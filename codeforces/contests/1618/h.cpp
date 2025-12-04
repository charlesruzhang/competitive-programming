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
    int n, q;
    cin >> n >> q;
    vvi a(n, vi(n));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    	}
    }
    vvl r(n + 1, vl(n + 1));
    vvl c(n + 1, vl(n + 1));
    vvl sr(n + 1, vl(n + 1));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		r[i+1][j+1] = r[i][j+1] - r[i][j] + r[i+1][j] + 1ll * i * a[i][j];
    		c[i+1][j+1] = c[i][j+1] - c[i][j] + c[i+1][j] + 1ll * j * a[i][j];
    		sr[i+1][j+1] = sr[i][j+1] - sr[i][j] + sr[i+1][j] + 1ll * a[i][j];
    	}
    }
    while (q--) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	x1--; y1--;
    	x2--; y2--;

    	ll R = r[x2 + 1][y2 + 1] - r[x2 + 1][y1] - r[x1][y2 + 1] + r[x1][y1];

    	ll SR = sr[x2 + 1][y2 + 1] - sr[x2 + 1][y1] - sr[x1][y2 + 1] + sr[x1][y1];

    	R -= SR * x1;
    	R *= (y2 - y1 + 1);


    	ll C = c[x2 + 1][y2 + 1] - c[x2 + 1][y1] - c[x1][y2 + 1] + c[x1][y1];
    	C += (1 - y1) * SR;

    	cout << R + C << " ";
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
