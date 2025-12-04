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
    int cur = 0;
    vi end(n);
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		if (i) end[i-1] = 1;
    		if (cur == 1) {
    			cout << "NO" << endl;
    			return;
    		} 
    		cur = 0;
    	} else {
    		cur++;
    	}
    }
    if (cur == 1) {
    	cout << "NO" << endl;
    	return;
    }
    end[n-1] = 1;
    cur = 0;
    vi ans(n);
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		ans[i] = i + 2;
    		cur ++;
    		if (end[i]) {
    			ans[i] -= cur;
    		}
    	} else {
    		cur = 0;
    		ans[i] = i + 1;
    	}
    }
    cout << "YES" << endl;
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
