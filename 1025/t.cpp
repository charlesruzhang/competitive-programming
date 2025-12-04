#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
void solve() {
	string s;
	cin >> s;
	char next = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {
			cout << "NO" << endl;
			return;
		}
		if (next != 0) {
			if (next == 'Y' && s[i] != 'e') {
				cout << "No" << endl;
				return;
			} else if (next == 'e' && s[i] != 's') {
				cout << "no" << endl;
				return;
			} else if (next == 's' && s[i] != 'Y') {
				cout << "No" << endl;
				return;
			}
		}
		next = s[i];
	}
	cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
