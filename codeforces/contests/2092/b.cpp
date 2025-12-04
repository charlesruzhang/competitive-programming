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
    string s;
    string t;
    cin >> s >> t;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++) {
    	if (i % 2) {
    		if (s[i] == '1') c1++;
    		if (t[i] == '1') c2++;
    	} else {
    		if (s[i] == '1') c2++;
    		if (t[i] == '1') c1++;
    	}
    }
    if (c1 <= (n + 1) / 2 && c2 <= n / 2) {
    	cout << "YES" << endl;
    } else {
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
