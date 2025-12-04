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
vi prime;
const int maxN = 2e7+5;
bool is_composite[maxN];

void sieve () {
	int n = maxN;
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
void solve() {
	int n;
	cin >> n;
	vi a(n);
	int X = 2e7;
	vi cnt(X+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];    	
		cnt[a[i]]++;
	}
	for (int i = X; i >= 1; i--) {
		for (int j = 0; j < prime.size(); j++) {
			int z = i * prime[j];
			if (z > X) break;
			cnt[i] += cnt[z];
		}
	}
	vl dp(X+1);
	ll ans = 0;
	for (int i = X; i >= 1; i--) {
		dp[i] = 1ll * cnt[i] * i; 
		for (int j = 0; j < prime.size(); j++) {
			int z = i * prime[j];
			if (z > X) break;
			dp[i] = max(dp[i], dp[z] + 1ll * (cnt[i] - cnt[z]) * i);	
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
