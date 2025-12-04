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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int tot = 0;
    vvi pref(n + 1, vi(m + 1));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int z = 0;
    		if (a[i][j] == 'g') {
    			tot++;
    			z = 1; 
    		}
    		pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + z;
    	}
    }


    int ans = tot;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j] == '.') {

    			int l = (j >= k) ? j - k + 1 : 0;
    			int r = (j + k < m) ? j + k : m;
    			int u = (i >= k) ? i - k + 1 : 0;
    			int d = (i + k < n) ? i + k : n;

    			int cur = pref[d][r] - pref[u][r] - pref[d][l] + pref[u][l]; 

    			// cout << i << " " << j << endl;
    			// cout << l << " " << r << " " << u << " " << d << endl;
    			// cout << "! " << cur << endl;
    			ans = min(ans, cur);
    		}
    	}
    }
    cout << tot - ans << endl;
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
