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
	vector<vector<char>> vc(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			vc[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vc[i][j] == '?') {
				function <bool(int, int)> f = [&] (int dx, int dy) {
					int x = i;
					int y = j;
					while (x >= 0 && y >= 0 && x < n && y < n) {
						if (vc[x][y] == '?' && (x != i || y != j)) {
							return false;
						}
						if (vc[x][y] != '.' && (x != i || y != j)) {
							break;
						}
						x += dx;
						y += dy;
					}
					return true;
				};
				if ((!f(0, 1)) || (!f(0, -1)) || (!f(1, 0)) || (!f(-1, 0))) {
					cout << 0<< endl;
					return;
				}
			} else if (vc[i][j] == '.') {
				function <bool(int, int)> f = [&] (int dx, int dy) {
					int x = i;
					int y = j;
					while (x >= 0 && y >= 0 && x < n && y < n) {
						if (vc[x][y] == '?' && (x != i || y != j)) {
							return true;
						}
						if (vc[x][y] != '.' && (x != i || y != j)) {
							break;
						}
						x += dx;
						y += dy;
					}
					return false;
				};
				if ((!f(0, 1)) && (!f(0, -1)) && (!f(1, 0)) && (!f(-1, 0))) {
					cout << 0 << endl;
					return;
				}
			} else if (vc[i][j] != 'X') {
				int v = vc[i][j] - '0';
				int cnt = 0;
				if (i && vc[i-1][j] == '?') cnt++;
				if (j && vc[i][j-1] == '?') cnt++;
				if (i != n - 1 && vc[i+1][j] == '?') cnt++;
				if (j != n - 1 && vc[i][j+1] == '?') cnt++;
				if (cnt != v) {
					cout << 0 << endl;
					return;
				}
			}
		}
	}
	cout << 1 << endl;

}

int main() {

	solve();
	return 0;
}