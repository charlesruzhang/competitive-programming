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
	int x;
	cin >> x;
	x--;
	vi a(20);
	int y = x;
	int cur = 0;
	while (y) {
		a[cur] = y % 2;
		y /= 2;
		cur++;
	}
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for (int i = 0; i < 15; i++) {
		if (i % 2 <= 0) {
			t1 ^= a[i];
		}
		if (i % 4 <= 1) {
			t2 ^= a[i];
		}
		if (i % 8 <= 3) {
			t3 ^= a[i];
		}
		if (i % 16 <= 7) {
			t4 ^= a[i];
		}
	}
	a[15] = t1;
	a[16] = t2;
	a[17] = t3;
	a[18] = t4;
	a[19] = t1 ^ t2 ^ t3 ^ t4;
	vi ans;
	for (int i = 0; i < 20; i++) {
		if (a[i]) {
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}
void solve2() {
	int n;
	cin >> n;
	vi a(n);
	vi c(20);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]-1] = 1;
	}
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for (int i = 0; i < 15; i++) {
		if (i % 2 <= 0) {
			t1 ^= c[i];
		}
		if (i % 4 <= 1) {
			t2 ^= c[i];
		}
		if (i % 8 <= 3) {
			t3 ^= c[i];
		}
		if (i % 16 <= 7) {
			t4 ^= c[i];
		}
	}
	int mis = 0;
	mis += (t1 != c[15] ? 1 : 0);
	mis += (t2 != c[16] ? 1 : 0);
	mis += (t3 != c[17] ? 1 : 0);
	mis += (t4 != c[18] ? 1 : 0);
	int x = c[19];
	if (x == c[15] ^ c[16] ^ c[17] ^ c[18]) {
		set<int> s;
		for (int i = 0; i < 15; i++) {
			int flag = 1;
			if (i % 2 <= 0 && t1 == c[15]) {
				flag = 0;
			}
			if (i % 4 <= 1 && t2 == c[16]) {
				flag = 0;
			}
			if (i % 8 <= 3 && t3 == c[17]) {
				flag = 0;
			}
			if (i % 16 <= 7 && t4 == c[18]) {
				flag = 0;
			}
			if (flag) {
				c[i] ^= 1;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 15; i++) {
		ans += c[i] * (1 << i);
	}
	cout << ans + 1 << endl;
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

