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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = s[i] == 's' ? 0 : 1;
    }
    vi pref(n + 1);
    for (int i = 0; i < n; i++) {
    	pref[i + 1] = pref[i] + a[i];
    }
    vi dp(n+1);
    int cnt = 0;
    for (int i = 2; i < n; i++) {
    	if (!a[i]) cnt++;
    	else cnt = 0;
    	if (3 * cnt <= i + 1) {
    		if (pref[i + 1] - pref[i + 1 - cnt] == 0) {
    			if (pref[i + 1 - cnt] - pref[i + 1 - cnt - cnt] == cnt) {
	    			if (pref[i + 1 - 2 * cnt] - pref[i + 1 - 3 * cnt] == 0) {
	    				dp[i + 1] = dp[i + 1 - 3 * cnt] + 3 * cnt;
	    			}
    			}
    		} 
    	}
    }
    int maxx = *max_element(dp.begin(), dp.end());
    cout << maxx << endl;
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
