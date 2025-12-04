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
    int n;
    cin >> n;
    if (n == 2) {
    	cout << -1 << endl;
    	return;
    }
	int m = (n + 1) / 2;
    vector<vector<char>> ans(m, vector<char>(m, '.'));
    if (n % 2) {
	    for (int i = 0; i < m; i++) {
	    	ans[0][i] = 'o';
	    	ans[i][0] = 'o';
	    }
    } else {
	    for (int i = 0; i < m; i++) {
	    	ans[0][i] = 'o';
	    	ans[i][0] = 'o';
	    }
	    ans[1][1] = 'o';
    }
    cout << m << endl;
    for (int i = m - 1; i >= 0; i--) {
    	for (int j = 0; j < m; j++) {
    		cout << ans[i][j];
    	}
    	cout << endl;
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
