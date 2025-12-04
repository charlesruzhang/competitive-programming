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
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int val = 0;
    for (int i = 1; i < n - 1; i++) {
    	if (val == 1 && s[i] == 's') {
    		cout << "NO" << endl;
    		return;
    	} else if (val == 2 && s[i] == 'p') {
    		cout << "NO" << endl;
    		return;
    	} else if (s[i] == 's') {
    		val = 2;
    	} else if (s[i] == 'p') {
    		val = 1;
    	}
    }
    if (s[0] == 'p' && val == 2) {
    	cout << "NO" << endl;
    	return;
    } 
    if (s[0] == 'p') val = 1;
    if (s[n-1] == 's' && val == 1) {
    	cout << "NO" << endl;
    	return;
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
