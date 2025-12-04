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
	vi a(16);
	int prev = 0;
    for (int i = 0; i <= 14; i++) {
    	if (i % 3 == i % 5) {
    		a[i] = prev+1;
    	} else {
    		a[i] = prev;
    	}
    	prev = a[i];
    }
    int n;
    cin >> n;
    int x = n / 15;
    int y = n % 15;
    cout << (a[y] + a[14] * x) << endl;
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
