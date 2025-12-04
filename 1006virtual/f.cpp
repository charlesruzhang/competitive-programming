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
const ll MAXX = 1e16;
void solve() {
    int n, k;
    cin >> n >> k;
    ll x = 1;
    cout << k << " ";
    int cur = 0;
    for (int i = 1; i < n; i++) {
    	int c = 0;
    	int a = n - i;
    	while (a > 0 && a % 2 == 0) {
    		c++;
    		a/=2;
    	}
    	a = i;
    	while (a > 0 && a % 2 == 0) {
    		c--;
    		a/=2;
    	}
    	cur += c;
    	if (cur == 0) {
    		cout << k << " ";
    	} else {
    		cout << 0 << " ";
    	}
    }
    cout << endl;
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
