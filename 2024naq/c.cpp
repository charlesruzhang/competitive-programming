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
	int x;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt += (x % 2 == 1);
	}
	cout << cnt << endl;
}

int main() {

	solve();
	return 0;
}