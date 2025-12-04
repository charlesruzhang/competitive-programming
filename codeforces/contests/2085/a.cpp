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
    string s;
    cin >> s;
    vector<char> c1(n), c2(n);
    for (int i = 0; i < n; i++) {
    	c1[i] = s[i];
    	c2[i] = s[n-i-1];
    }
    if (k == 0) {
    	if (c1 >= c2) {
    		cout << "NO" << endl;
    		return;
    	} else {
    		cout << "YES" << endl;
    		return;
    	}

    } else {
    	for (int i = 1; i < n; i++) {
    		if (c1[i] != c1[i-1]) {
    			cout << "YES" << endl;
    			return;
    		}
    	}
    	cout << "NO" << endl;
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
