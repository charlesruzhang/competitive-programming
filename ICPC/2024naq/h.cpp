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
	vi p1(n), p2(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> p1[i] >> p2[i];
		string ch;
		cin >> ch;
		c[i] = ch[0] - 'a';
	}
	vi L(n, 1e9+7);
	for (int i = 0; i < (1 << n); i++) {
		int flag = 1;
		for (int j = 0; j < n; j++) {
			if ((1 << j) & i) {
				if (p2[j] == 0) {
					flag = 0;
					break;
				}
			} 
		}
		if (!flag) continue;
		vi l(n), r(n);
		for (int i = 0; i < n; i++) {
			l[i] = c[i];
			r[i] = 19;
		}
		flag = 1;
		for (int j = n - 1; j >= 0; j--) {
			if ((1 << j) & i) {
				int P = p2[j] - 1;
				int Q = p1[j] - 1;
				l[Q] = max(l[Q], l[j]);
				if (c[P] != c[j]) {
					if (c[j] > r[P] || c[j] < l[P]) {
						flag = 0;
						break;
					}
					l[P] = r[P] = c[j];
				}
			} else if (p2[j] == 0) {
				continue;
			} else {
				int P = p1[j] - 1;
				int Q = p2[j] - 1;
				l[Q] = max(l[Q], l[j]);
				if (c[P] != c[j]) {
					if (c[j] > r[P] || c[j] < l[P]) {
						flag = 0;
						break;
					}
					l[P] = r[P] = c[j];
				}
			}
		}
		if (!flag) continue;
		for (int j = 0; j < n; j++) {
			if ((1 << j) & i) {
				int P = p2[j] - 1;
				int Q = p1[j] - 1;
				if (c[P] != c[j]) {
					if (l[P] != c[j]) {
						flag = 0;
						break;
					}
				}
				if (l[j] > l[Q]) {
					flag = 0;
					break;
				}
				if (l[j] == )
			} else if (p2[j] != 0) {
				int P = p1[j] - 1;
				int Q = p2[j] - 1;
				if (c[P] != c[j]) {
				}
			}
			r[j] = l[j];	
		}
		if (l < L) {
			swap(l, L);
		}
	}
	if (L[0] == 1e9+7) {
		cout << -1 << endl;
	} else {
		for (int i = 0; i < n; i++) {
			char ch = (char)(c[i] + 'a');
			char chl = (char)(L[i] + 'a');
			cout << ch << chl << endl;
		}
	}
}

int main() {

	solve();
	return 0;
}