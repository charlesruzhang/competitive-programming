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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int l = 0;
    int r = n / k;
    function <bool(int)> check = [&] (int m) {
    	int cur = 0;
    	int curk = 0;
    	int tot = 0;
    	vi vec(m);
    	while (curk < k) {
    		while (tot < m && cur < n) {
    			if (a[cur] < m && !vec[a[cur]]) {
    				vec[a[cur]] = 1;
    				tot++;
    			}
    			cur++;
    		}
    		if (tot == m) {
    			tot = 0;
    			curk++;
    			vi vv(m);
    			swap(vv, vec);
    		}
    		if (cur >= n && curk < k) {
    			return false;
    		}
    	}
    	return true;
    };
    while (l < r) {
    	int m = (l + r + 1) / 2; 
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    cout << l << endl;	
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
