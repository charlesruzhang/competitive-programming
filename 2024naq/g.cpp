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
	int n;
	cin >> n;
	vvi S(1e5+1);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		S[x].push_back(y);
	}
	for (int i = 1; i <= 1e5; i++) {
		sort(S[i].begin(), S[i].end());
	}
	long double ans = 0;
	for (int i = 1; i <= 1e5; i++) {
		int x = S[i].size();
		for (int j = 0; j < x / 2; j++) {
			ans += log(S[i][x - j - 1]) - log(S[i][j]);
		}	
	}
	cout << setprecision(10) << ans << endl;
}

int main() {

	solve();
	return 0;
}