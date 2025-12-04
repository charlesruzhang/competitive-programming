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
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
    	cout << -1 << endl;
    	return;
    }
    for (int i = 0; i < n - 2; i++) {
    	if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
    		cout << s[i] << s[i+1] << s[i+2] << endl;
    		return;
    	}
    	if (s[i] == s[i+1]) {
    		cout << s[i] << s[i+1] << endl;
    		return;
    	}
    }
    if (s[n-2] == s[n-1]) {
    	cout << s[n-2] << s[n-1] << endl;
    	return;
    }
    cout << -1 << endl;
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
