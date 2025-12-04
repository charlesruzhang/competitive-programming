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
	double minn = 1e6;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) continue;
		if (x1 * x2 > 0) continue;
		double b = (double) (y1 * x2 - y2 * x1) / (x2 - x1);
		if (b > 0) {
			minn = min(minn, b);
		}
	}
	cout << setprecision(10) << (minn == 1e6 ? -1.0 : minn) << endl;
}

int main() {

	solve();
	return 0;
}