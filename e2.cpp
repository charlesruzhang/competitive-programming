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
vi f2(5e5+1, 1e9);
void comp2() {
	f2[1] = 1;
	for (int i = 3; i <= 5e5; i+=2) {
		int cur = i;
		int ans = 1;
		for (int j = 3; j * j <= i; j+=2) {
			while (cur % j == 0) {
				ans += f2[j] - 1;
				f2[i] = min(f2[i], ans + 1 + f2[cur-2]);
				cur /= j;
			}
 
		}
		if (cur > 1) {
			if (f2[cur] != -1) {
				ans += f2[cur] - 1;
				f2[i] = min(f2[i], ans);
			}
		} else {
			f2[i] = min(f2[i], ans);
		}
 
		f2[i] = min(f2[i], 1 + f2[i - 2]);
	}
}
void solve() {
    for (int i = 1; i <= 5e5; i+=2) {
    	if (f[i] != f2[i]) {
    		cout << i << " "<< f[i] << " " << f2[i] << endl;
    	}
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    comp2();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
