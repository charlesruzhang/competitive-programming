#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	string s;
	cin >> s;
	string t;
	cin >> t;
	int n = s.size();
	int m = t.size();
	int h = 0, v = 0;
	for (int i = 0; i < m; i++) {
		if (t[i] == 'h') {
			h ^= 1;
		} else if (t[i] == 'v') {
			v ^= 1;
		} else {
			h ^= 1;
			v ^= 1;
		}
	}
	if (v) {
		string ans;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'b') {
				ans += 'p';
			} else if (s[i] == 'p') {
				ans += 'b';
			} else if (s[i] == 'q') {
				ans += 'd';
			} else {
				ans += 'q';
			}
		}
		swap(ans, s);
	} 
	if (h) {
		string ans;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'b') {
				ans += 'd';
			} else if (s[i] == 'p') {
				ans += 'q';
			} else if (s[i] == 'q') {
				ans += 'p';
			} else {
				ans += 'b';
			}
		}
		swap(ans, s);
	}
	cout << s << endl;
}


int main() {
	solve();
	return 0;
}