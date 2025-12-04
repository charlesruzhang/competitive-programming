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
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cout << ((2 * i * m) % (n * m)) + 1 + j << " ";
    		}
    		cout << endl;
    	}
    } else if (m % 2 == 0) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cout << i * m + 1 + j << " ";
    		}
    		cout << endl;
    	}
    } else {
    	swap(n, m);
    	vvi ans(n, vi(m));
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			ans[i][j] = ((2 * i * m) % (n * m)) + 1 + j;
    		}
    	}
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			cout << ans[j][i] << " ";
    		}
    		cout << endl;
    	}
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
