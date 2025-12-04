// By Auchenai01
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
const int INF = 1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vi a(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < 8; j++) {
			int rem = x % 26;
			x /= 26;
			s += (char) (rem + 'a');
		}
	}
	cout << s << endl;
}
void solve2() {
	string s;
	cin >> s;
	int n = s.size();
	vi a(n / 8);
	for (int i = 0; i < n / 8; i++) {
		for (int j = 0; j < 8; j++) {
			int rem = s[8 * i + j] - 'a';
			for (int k = 0; k < j; k++) {
				rem *= 26;
			}
			a[i] += rem;
		}
	}
	cout << n / 8 << endl;
	for (int i = 0; i < n / 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
    	string s;
    	cin >> s;
    	if (s == "first") {
        	solve();
    	} else if (s == "second") {
        	solve2();
    	}
    }
    return 0;
}

