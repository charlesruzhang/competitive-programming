#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	vvi cnt(1e5+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]].push_back(i);
	}
	string t;
	set<array<int, 3>> s;
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {
			s.insert({l, i - 1, t[i-1] - '0'});
			l = i;
		} 
	}
	s.insert({l, n - 1, t[n-1] - '0'});
	for (int i = 1; i <= 1e5; i++) {
		for (int x : cnt[i]) {
			auto it = s.lower_bound({x, 0, 0});
		}
	}
}

int main() {
	solve();
	return 0;
}