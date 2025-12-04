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
void solve() {
    int n;
    cin >> n;
    vi a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
    	cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < (1 << n); j+=(1 << i)) {
    		if (a[j] > a[j + (1 << (i - 1))]) {
    			for (int k = 0; k < (1 << (i - 1)); k++) {
    				swap(a[j + k], a[j + (1 << (i - 1)) + k]);
    			}
    		}
    	}
    }
    for (int i = 0; i < (1 << n); i++) {
    	cout << a[i] << " ";
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
