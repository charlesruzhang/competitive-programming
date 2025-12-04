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
	vl hash(n+1);
	vector<string> vs(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
		hash[i+1] = hash[i] * 197;
		auto& s = vs[i];
		if (s.size() == 1 && ((s[0] < 'z' && s[0] > 'a') || (s[0] < 'Z' && s[0] > 'A'))) {
			hash[i+1] += 131;
			continue;
		}
		ll H = 0;
		for (int j = 0; j < s.size(); j++) {
			H = H * 137 + s[j];
		}
		hash[i+1] = hash[i] + H;
	}
	vl p(2001, 1);
	for (int i = 1; i <= 2000; i++) {
		p[i] = p[i-1] * 197;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int m;
		cin >> m;
		vector<string> qr(m);
		vi mark(m);
		vl hq(m+1);
		for (int j = 0; j < m; j++) {
			cin >> qr[j];
			auto& s = qr[j];
			hq[i+1] = hq[i] * 197;
			if (s.size() == 1 && ((s[0] < 'z' && s[0] > 'a') || (s[0] < 'Z' && s[0] > 'A'))) {
				hq[i+1] += 131;
				continue;
			}
			ll H = 0;
			for (int z = 0; z < s.size(); z++) {
				H = H * 137 + s[z];
			}
			hq[i+1] = hq[i] + H;
		}

		for (int j = m - 1; j < n; j++) {
			if (hq[m] == hash[j+1] - hash[j+1-m] * p[m]) {
				for (int z = 0; z < m; z++) {
					
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	//cin >> t;
	solve();
	return 0;
}