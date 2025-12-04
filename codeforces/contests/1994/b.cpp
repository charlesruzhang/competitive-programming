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
    string s;
    string t;
    cin >> s >> t;
    if (s == t) {
    	cout << "YES" << endl;
    	return;
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0' && t[i] == '1') {
    		cout << "NO" << endl;
    		return;
    	}
    	if (s[i] == '1') {
    		cout << "YES"  << endl;
    		return;
    	}
    }
    assert(false);
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
