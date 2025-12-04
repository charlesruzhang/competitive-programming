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
    int l = 1;
    int h = n + 1;
    vvi ans(2, vi(n));
    ans[0][0] = 2 * n;
    for (int i = 1; i < n; i++) {
    	if (i % 2 == 0) {
    		ans[0][i] = h++;
    	} else {
    		ans[1][i] = h++;
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (i % 2 == 0) {
    		ans[1][i] = l++;
    	} else {
    		ans[0][i] = l++;
    	}
    }
    for (int i = 0; i < 2; i++) {
    	for (int j = 0; j < n; j++) {
    		cout << ans[i][j] << " ";
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
