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
    int m = n * k;
    vi a(m);
    for (int i = 0; i < n * k; i++) {
    	int x; cin >> x; 
    	a[i] = x - 1;
    }
    int count = 0;
    vector<pii> ans(n);
    vi done(n, 0);
    while (count < n) {
    	vi dup(n, -1);
    	int idx = 0;
    	while (idx < m) {
    		int x = a[idx];
    		if (!done[x]) {
	    		if (dup[x] != -1) {
	    			ans[x] = pii(dup[x], idx);
	    			done[x] = 1;
	    			count++;
	    			vi dup2(n, -1);
	    			swap(dup, dup2);
	    		} else {
	    			dup[x] = idx;
	    		}
	    	}
	    	idx++;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
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

