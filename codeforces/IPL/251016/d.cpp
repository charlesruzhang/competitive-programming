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
    vi last(26, -1);
    vi dp(n+1);
    for (int i = 0; i < n; i++) {
    	int z = s[i] - 'a';
    	dp[i+1] = dp[i];
    	if (last[z] != -1) {
    		dp[i+1] = max(dp[i+1], dp[last[z]] + 2);
    	} 
    	last[z] = i;
    }
    cout << n - dp[n] << endl;
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
