#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	int n;
	cin >> n;
	vi c1, c2, c3;
	map<pair<string, int>, int> store;
	vector<pair<string, int>> st(n);
	vi used(n);
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		store[{s, x}] = i;
		if (s == "+" && x % 2 == 1) {
			c1.push_back(i);
		} else if (s == "*" && x % 2 == 0) {
			c3.push_back(i);
		} else {
			c2.push_back(i);
		}
		st[i] = {s, x};
	}
	int start;
	cin >> start;
	int x = c1.size();
	int y = c2.size();
	int z = c3.size();
	vector<vector<vvi>> dp(x + 1, vector<vvi>(y+1, vvi(z + 1, vi(2))));
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			for (int k = 0; k <= z; k++) {
				for (int t = 0; t < 2; t++) {
					
					int turn = (i + j + k + x + y + z) % 2;
					if (turn) {
						dp[i][j][k][t] = 1;
					} else {
						dp[i][j][k][t] = 0;
					}
					if (i == 0 && j == 0 && k == 0) {
						dp[i][j][k][t] = t;
					}
					if (i && !turn) {
						dp[i][j][k][t] = max(dp[i][j][k][t], dp[i-1][j][k][t^1]);
					}
					if (i && turn) {
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i-1][j][k][t^1]);
					}
					if (j && !turn) {
						dp[i][j][k][t] = max(dp[i][j][k][t], dp[i][j-1][k][t]);
					}
					if (j && turn) {
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i][j-1][k][t]);
					}
					if (k && !turn) {
						dp[i][j][k][t] = max(dp[i][j][k][t], dp[i][j][k-1][0]);
					}
					if (k && turn) {
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i][j][k-1][0]);
					}
					//cout << i << " " << j << " " << k << " " << t << " " << dp[i][j][k][t] << endl;
				}
			}
		}
	}
	int flag = 0;
	if (dp[x][y][z][start % 2]) {
		cout << "me" << endl;
		flag = 1;
	} else {
		cout << "you" << endl;
	}
	int cx = x, cy = y, cz = z;
	int cur = start % 2;
	for (int i = 0; i < x + y + z; i++) {
		if ((i + flag) % 2 == 0) {
			string s;
			int val;
			cin >> s >> val;
			int z = store[{s, val}];
			used[z] = 1;
			if (s == "+" && val % 2 == 1) {
				cx--;
				cur ^= 1;
			} else if (s == "*" && val % 2 == 0) {
				cz--;
				cur = 0;
			} else {
				cy--;
			}
		} else {
			assert(dp[cx][cy][cz][cur] == flag);
			if (cx && dp[cx-1][cy][cz][cur^1] == flag) {
				cur = cur ^ 1;
				cx--;
				while (used[c1.back()]) {
					c1.pop_back();
				}
				int idx = c1.back();
				c1.pop_back();
				used[idx] = 1;
				auto [s, v] = st[idx];
				cout << s << " " << v << endl;
			} else if (cy && dp[cx][cy-1][cz][cur] == flag) {
				cy--;
				while (used[c2.back()]) {
					c2.pop_back();
				}
				int idx = c2.back();
				c2.pop_back();
				used[idx] = 1;
				auto [s, v] = st[idx];
				cout << s << " " << v << endl;
			} else if (cz && dp[cx][cy][cz-1][0] == flag) {
				cur = 0;
				cz--;
				while (used[c3.back()]) {
					c3.pop_back();
				}
				int idx = c3.back();
				c3.pop_back();
				used[idx] = 1;
				auto [s, v] = st[idx];
				cout << s << " " << v << endl;
			} else {
				assert(false);
			}
		}
	}
}


int main() {
	int t;
	//cin >> t;
	solve();
	return 0;
}