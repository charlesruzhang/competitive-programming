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
    string t;
    cin >> t;
    vi cnt(k);
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < k; j++) {
    		if (s[j] == '1') {
    			cnt[j]++;
    		}
    	}
    }
    vector<vector<pii>> dp(k + 1, vector<pii>(2 * n + 1, {-1, 0}));
    dp[k][0] = {k, 0};
    for (int i = k - 1; i >= 0; i--) {
    	int C = 0;
    	for (int j = 0; j <= 2 * n; j++) {
    		if (j / 2 + cnt[i] <= 2 * n && dp[i+1][j].first != -1) {
    			dp[i][j / 2 + cnt[i]] = {j, 0};
    		}
    		if (j / 2 + n - cnt[i] <= 2 * n && dp[i+1][j].first != -1) {
    			dp[i][j / 2 + n - cnt[i]] = {j, 1};
    		}
    		
    	}
    	for (int j = 0; j <= 2 * n; j++) {
    		if ((j & 1) != t[i] - '0') {
    			dp[i][j] = {-1, 0};
    		} else if (dp[i][j].first != -1) {
    			C++;
    		}
    	}
    	if (C == 0) {
    		cout << -1 << endl;
    		return;
    	}
    }
    if (dp[0][t[0] - '0'].first != -1) {
    	vi ans;
    	int now = t[0] - '0';
    	for (int i = 0; i < k; i++) {
    		ans.push_back(dp[i][now].second);
    		now = dp[i][now].first;
    		assert(now != -1);
    	}
    	for (int z : ans) {
    		cout << z;
    	}
    	cout << endl;
    } else {
    	cout << -1 << endl;
    	return;
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
