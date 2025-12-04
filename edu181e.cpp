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
vi f(5e5+1, 1e9);
void comp() {
	f[1] = 1;
	for (int i = 3; i <= 5e5; i+=2) {
		int cur = i;
		int ans = 1;
		vi vec;
		for (int j = 1; j * j <= i; j+=2) {
			if (i % j == 0) {
				vec.push_back(j);
				if (j * j != i) vec.push_back(i / j);
			}
		}
		for (int x : vec) {
			if (i / x != i) f[i] = min(f[i], f[x] + f[i / x] - 1);
			else f[i] = min(f[i], f[i - 2] + 1);
		}
	}
}
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
    	cout << -1 << endl;
    	return;
    }
    cout << f[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
