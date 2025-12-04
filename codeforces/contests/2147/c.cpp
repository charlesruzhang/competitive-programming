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
    cin >> s;
    vi used(n);
    vi flex(n);
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		if (!i || i == n-1) {
    			flex[i] = 1;
    			continue;
    		}
    		if (s[i-1] == '0' || s[i+1] == '0') {
    			flex[i] = 1;
    			continue;
    		}
    		if (used[i]) continue;
    		if (i >= 2 && s[i-2] == '0') {
    			if (flex[i-2]) {
    				flex[i] = 1;
    				continue;
    			} else if (!used[i-2]) {
    				used[i] = 1;
    				continue;
    			}
    		}
    		if (i + 2 < n && s[i + 2] == '0') {
    			used[i] = used[i+2] = 1;
    		} else {
    			cout << "NO" << endl;
    			return;
    		}
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
