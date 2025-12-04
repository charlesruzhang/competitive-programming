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
	vi cnt(51);
	int x;
	for (int i = 0; i < 10 * n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> x;
			cnt[x]++;
		}
	}
	int flag = 0;
	for (int i = 1; i <= 50; i++) {
		if (cnt[i] > 2 * n) {
			cout << i << " ";
			flag = 1;
		}
	}
	if (!flag) {
		cout << -1 << endl;
	} else {

		cout << endl;
	}
}

int main() {

	solve();
	return 0;
}