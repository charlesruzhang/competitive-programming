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
	int n, k;
	cin >> n >> k;
	vi b;
	int cnt = 0;
	vvi va;
	va.push_back({});
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int val;
		cin >> val;
		if (s == "m") {
			b.push_back(val);
			cnt++;
			va.push_back({});
		} else {
			va[cnt].push_back(val);
		}
	}
	int m = cnt;
	vvl pref(m);
	for (int i = 0; i < m; i++) {
		pref[i].resize(va[i].size() + 1);
		sort(va[i].begin(), va[i].end(), greater<>());
		for (int j = 0; j < va[i].size(); j++) {
			pref[i][j+1] = pref[i][j] + va[i][j];
		}
	}
	vl ans(n);
	vvl dp(m + 1, vl(n));
	for (int i = 1; i <= m; i++) {
		vvl ndp(m + 1, vl(n));
		for (int j = i - 1; j < m; j++) {
			for (int k = i - 2; k < j; k++) {
				
			}
		}
	}
}

int main() {

	solve();
	return 0;
}