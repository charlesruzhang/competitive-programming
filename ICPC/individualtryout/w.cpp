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
    vi nxt(n + 1, -1);
    vector<set<pii, greater<>>> S(26);
    vi dp(n + 1, -INF);
    S[s[n-1] - 'a'].insert({0, n - 1});
    for (int i = n - 1; i >= 0; i--) {
    	int z = s[i] - 'a';
		auto it = S[z].begin();
		if (it != S[z].end() && it -> second == i) {
			++it;
		}
		if (it == S[z].end()) continue;
		nxt[i] = it -> second + 1;
		dp[i] = it -> first + 1;
		if (i) {
			S[s[i-1] - 'a'].insert({dp[i], i - 1});
		} 
    }
    if (dp[0] == -INF) cout << -1 << endl;
    else {
    	cout << dp[0] << endl;
	    int cur = 0;
	    while (cur < n) {
	    	int prev = cur;
	    	cur = nxt[cur];
	    	cout << cur - prev << " ";
	    }
	    cout << endl;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
