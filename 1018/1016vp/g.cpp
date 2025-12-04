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
    int n, k;
    cin >> n >> k;
    vi a(n);
    vector<vector<int>> vec;
    vector<int> maxx;
    vec.reserve(31 * n);
    maxx.reserve(31 * n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (k == 0) {
    	cout << 1 << endl;
    	return;
    }
    vec.push_back({-1, -1});
    maxx.push_back(-1);
    int tot = 1;
    int ans = 1e9 + 7;
    for (int i = 0; i < n; i++) {
    	vector<int> cur = vec[0];
    	int curmax = -1;
    	for (int x = 30; x >= 0; x--) {
    		int y = (a[i] & (1 << x)) > 0;
    		if (k & (1 << x)) {
    			if (cur[1-y] == -1) {
    				break;
    			}
    			if (!x) curmax = max(curmax, maxx[cur[1-y]]);
    			cur = vec[cur[1-y]];
    		} else {
    			if (cur[1-y] != -1) {
    				curmax = max(curmax, maxx[cur[1-y]]);
    			}
    			if (cur[y] == -1) {
    				break;
    			}
    			if (!x) curmax = max(curmax, maxx[cur[y]]);
    			cur = vec[cur[y]];
    		}
    	}
    	cur = vec[0];
    	int curc = 0;
    	for (int x = 30; x >= 0; x--) {
    		maxx[curc] = i;
    		int y = (a[i] & (1 << x)) > 0;
			if (cur[y] == -1) {
				vec.push_back({-1, -1});
				maxx.push_back(i);
				vec[curc][y] = tot;
				cur[y] = tot;
				tot++;
			}
			curc = cur[y];
			cur = vec[curc];
    	}
    	maxx[curc] = i;
    	if (curmax != -1) ans = min(ans, i - curmax + 1);
    	//cout << i << " " << curmax << endl;
    }
    if (ans == 1e9 + 7) {
    	cout << -1 << endl;
    } else {
    	cout << ans << endl;
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
