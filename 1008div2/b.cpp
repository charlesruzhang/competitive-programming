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
    int n, k;
    cin >> n >> k;
    if (k % 2) {
    	for (int i = 0; i < n-1; i++) {
    		cout << n << " ";
    	}
    	cout << n-1 << endl;
    	return;
    } else {
    	for (int i = 0; i < n-2; i++) {
    		cout << n-1 << " ";
    	}
    	cout << n << " " << n-1 << endl;
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
