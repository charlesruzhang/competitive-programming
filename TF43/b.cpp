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
    if (n < 4) {
    	cout << -1 << endl;
    	return;
    }
    vi ans;
    if (n % 2 == 1) {

	    for (int i = 1; i <= n; i++) {
	    	if (i == 4 || i == 2) {
	    		continue;
	    	}
	    	ans.push_back(i);
	    }
	    ans.push_back(4);
	    ans.push_back(2);
    } else {
    	for (int i = 1; i <= n; i++) {
	    	if (i == 2) {
	    		continue;
	    	}
	    	ans.push_back(i);
	    }
	    ans.push_back(2);
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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
