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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int t = 0;
    int u = 0, tm = 0, um = 0;
    for (int i = 0; i < k; i++) {
    	if (s[i] == '2') {
    		tm++;
    		um++;
    	} else if (s[i] == '0') {
    		t++;
    		tm++;
    	} else {
    		u++;
    		um++;
    	}
    }
    vector<char> ans(n, '?');
    for (int i = 0; i < n; i++) {
    	if (i >= t) {
    		if (i >= tm) {
    			continue;
    		} else {
    			if (n - i - 1 >= u) {
    				if (n - i - 1 >= um) {
    					continue;
    				} else {
    					ans[i] = '+';
    				}
    			} else {
    				ans[i] = '-';
    			}
    		}
    	} else {
    		ans[i] = '-';
    	}
    }
    for (char c: ans) {
    	cout << c;
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
