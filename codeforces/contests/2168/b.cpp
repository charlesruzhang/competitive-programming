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
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			x = i;
		} else if (a[i] == n) {
			y = i;
		}
	}
	cout << (x < y ? 0 : 1) << endl;
}
int query(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void solve2() {
	int n, x;
	cin >> n >> x;
	if (x == 0) {
		int l = 0;
		int r = n - 1;
		while (l < r) {
			int m = (l + r) / 2;
			int res = query(0, m);
			if (res == n - 1) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << "! " << l + 1 << endl;
	} else {
		int l = 0;
		int r = n - 1;
		while (l < r) {
			int m = (l + r + 1) / 2;
			int res = query(m, n - 1);
			if (res == n - 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		cout << "! " << l + 1 << endl;
	}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	string s;
	cin >> s;
    ll t = 1;
    cin >> t;
    while (t--) {
    	if (s == "first") {
        	solve();
    	} else if (s == "second") {
        	solve2();
    	}
    }
    return 0;
}

