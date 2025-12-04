#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vvl dp(n+1, vl(m+1));
	auto f = [&] (int x, int y) {
		if (x < y) swap(x, y);
		if (x - y <= 15) {
			return 7;
		}
		if (x - y <= 23) {
			return 6;
		}
		if (x - y <= 43) {
			return 4;
		}
		if (x - y <= 102) {
			return 2;
		}
		return 0;
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] + f(a[i-1], b[j-1]));
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}
	cout << dp[n][m] << endl;
}

int main() {

	solve();
	return 0;
}