#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;

void solve() {
	double a, b;
	int n, x1, xn;
	cin >> a >> b >> n >> x1 >> xn;
	if (n == 2) {
		cout << x1 << endl;
		cout << xn << endl;
		return;
	}
	vector<pair<double, double>> x(n+1);
	x[0] = {0, x1};
	x[1] = {1, 0};
	for (int i = 2; i < n; i++) {
		auto [a1, a2] = x[i-2];
		auto [b1, b2] = x[i-1];
		x[i] = {a1 * b + b1 * a, a2 * b + b2 * a}; 
	}
	double Y = (xn - x[n-1].second) / x[n-1].first;
	for (int i = 0; i < n; i++) {
		auto [a1, a2] = x[i];
		cout << setprecision(10) << a1 * Y + a2 << endl;
	}
}

int main() {
	solve();
	return 0;
}