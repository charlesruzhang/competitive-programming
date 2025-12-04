#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	double t;
	cin >> n >> m >> t;
	vector<vector<double>> dp(n, vector<double>(m));
	vector<vector<double>> dp2(n, vector<double>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			double minn = 1e18;
			if (i) minn = min(minn, dp[i-1][j]);
			if (j) minn = min(minn, dp2[i][j-1] + t / 2);
			dp[i][j] = minn;
		}
	}
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}