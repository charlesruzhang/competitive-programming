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
	vector<vector<char>> vc(n, vector<char>(m));
	int start = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			vc[i][j] = s[j];
			if (s[j] == 'A') {
				start = i * m + n;
			}
		}
	}
}

int main() {

	solve();
	return 0;
}