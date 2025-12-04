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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi ans(19);
    for (int i = 0; i < 19; i++) {
    	ans[i] = i + 2;
    }
    for (int i = 0; i < min(n, 21); i++) {
    	int tar = i + 2;
    	int flag = 0;
    	for (int v : ans) {
    		if (v > tar) {
    			break;
    		}
    		if (a[i] % v != 0) {
    			flag = 1;
    			break;
    		}
    	}
    	if (!flag) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    cout << "YES" << endl;
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
