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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi Q;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '?') {
    		Q.push_back(i);
    		s[i] = 'I';
    	}
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'X') {
    		tot += 10;
    	} else if (s[i] == 'V') {
    		tot += 5;
    	} else if (i == n - 1 || s[i+1] == 'I') {
    		tot += 1;
    	} else {
    		tot -= 1;
    	}
    }
    int m = Q.size();
    vi ans(m + 1);
    ans[0] = tot;
    int j = 0;
    vi done(m);
    auto F = [&] (int t, int delta) {
	    for (int i = 0; i < m; i++) {
	    	if (done[i]) continue;
	    	int idx = Q[i];
	    	int type = 0;
	    	if (!idx || s[idx-1] != 'I') {
	    		type |= 2;
	    	}
	    	if (idx != n - 1 && s[idx + 1] != 'I') {
	    		type |= 1;
	    	}
	    	if (type == t) {
	    		tot += delta;
	    		ans[++j] = tot;
	    		s[idx] = 'V'; 
	    		done[i] = 1;
	    	}
	    }
	};
	F(0, 2), F(1, 4), F(2, 4), F(3, 6);
    for (int i = 0; i < q; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	if (z >= m) {
    		z = m;
    		x = 0;
    	} else if (y + z >= m) {
    		x = 0;
    	} else {
    		x = m - y - z;
    	}
    	cout << ans[m - z] + 5 * x << endl;
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
