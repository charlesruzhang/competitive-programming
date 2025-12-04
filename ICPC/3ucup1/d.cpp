#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;

int query(int time, int idx) {
	int x = time % 60;
	int y = time / 60;
	cout << "at " << (y < 10 ? "0" : "") << y << ":" << (x < 10 ? "0" : "") << x << " check " << idx << endl;
	string s;
	cin >> s;
	if (s == "asleep") {
		return 1;
	} else {
		return 0;
	}
}

void solve() {
	int n;
	cin >> n;
	vi ans(n + 1);
	for (int i = 1; i <= n; i++) {
		int l = 0;
		int r = 1439;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (query(m, i)) {
				r = m - 1;
			} else {
				l = m;
			}
		}
		ans[i] = l + 1;
		if (l == 1439) {
		    ans[i] = 0;
		}
	}
	cout << "answer" << endl;
	for (int i = 1; i <= n; i++) {
		int x = ans[i] % 60;
		int y = ans[i] / 60;
		cout << (y < 10 ? "0" : "") << y << ":" << (x < 10 ? "0" : "") << x << endl;
	}
}

int main() {
	solve();
	return 0;
}