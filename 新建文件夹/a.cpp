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
		vi x(3);
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		int flag = 0;
		for (int j = 0; j < 3; j++) {
			if (s[j] == '?') {
				flag  = 1;
			}
		}
		if (flag) {
			for (int j = 0; j < 3; j++) {
				if (s[j] != '?') {
					x[s[j] - 'A']++;
				}
			}
		}
	}
	for (int i = 0; i< 3; i++ ){
		if ()
	}
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
