// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = int;
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
    array<int, 2> p = {131, 137};
    vector<vector<ll>> P(2, vl(n+1));
    P[0][0] = 1;
    P[1][0] = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < 2; j++) {
    		P[j][i] = P[j][i-1] * p[j]; 
    	}
    }
    vector<vector<ll>> V(2, vl(n + 1));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 2; j++) {
    		V[j][i+1] = V[j][i] * p[j] + s[i];
    	}
    }
    vector<vector<ll>> W(2, vl(n + 1));
    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j < 2; j++) {
    		W[j][i] = W[j][i+1] * p[j] + s[i];
    	}
    }
    array<ll, 2> ret;
    auto G = [&] (int l, int r) {
    	int x = r - l + 1;
    	ll L1 = V[0][l] * P[0][x];
    	ll L2 = V[1][l] * P[1][x];
    	ret = {V[0][r + 1] - L1, V[1][r + 1] - L2};
    };
    auto H = [&] (int l, int r) {
    	int x = r - l + 1;
    	ll R1 = W[0][r+1] * P[0][x];
    	ll R2 = W[1][r+1] * P[1][x];
    	ret = {W[0][l] - R1, W[1][l] - R2};
    };
    ll ans = 0;
    vi dp(n);
    for (int i = 0; i < n; i++) {
    	int sz = (i + 1) / 2;
    	if (sz == 0) {
    		dp[i] = 1;
    		ans += 1;
    		continue;
    	}
    	G(0, sz - 1);
    	auto L = ret;
    	H(i - sz + 1, i);
    	if (L == ret) {
    		dp[i] = dp[sz - 1] + 1; 
    	}
    	ans += dp[i];
    }
    cout << ans << endl;
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
