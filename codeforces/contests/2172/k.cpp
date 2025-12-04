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
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    }
    vi ans(1e6+1);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		// start = {i, j};
    		// right;
    		if (vs[i][j] == '+' || vs[i][j] == '*') {
    			continue;
    		}
    		// ans = A + B * D;
    		ans[vs[i][j] - '0']++;
    		auto f = [&] (int curx, int cury, pii dir) {
	    		ll A = 0;
	    		ll B = 1;
	    		int C = 0;
	    		ll D = vs[i][j] - '0';
    			curx += dir.first;
    			cury += dir.second;
    			while (curx < n && cury < m && curx >= 0 && cury >= 0) {
	    			if (vs[curx][cury] == '+') {
	    				if (C == 1) break;
	    				A += B * D;
	    				D = 0;
	    				C = 1;
	    				B = 1;
	    			} else if (vs[curx][cury] == '*') {
	    				if (C == 1) break;
	    				B *= D;
	    				D = 0;
	    				C = 1;
	    			} else {
	    				C = 0;
	    				if (D >= 1e7) break;
	    				D = 10 * D + (vs[curx][cury] - '0');
	    				if (A + B * D > 1e6) break;
	    				ans[A + B * D]++;
	    			}
	    			curx += dir.first;
	    			cury += dir.second;
	    		}
    		};
    		f(i, j, {0, 1});
    		f(i, j, {1, 0});
    		f(i, j, {0, -1});
    		f(i, j, {-1, 0});
    		f(i, j, {1, 1});
    		f(i, j, {1, -1});
    		f(i, j, {-1, -1});
    		f(i, j, {-1, 1});
    	}
    }
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	cout << ans[x] << endl;
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
