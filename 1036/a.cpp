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
    vi a(n);
    for (int c = 0; c < n; c++) {
    	cin >> a[c];
    }
    for (int i = 1; i < n; i++) {
    	if (a[i-1] > a[i]) {
    		cout << "Yes" << endl;
    		cout << 2 << endl;
    		cout << a[i-1] << " " << a[i] << endl;
    		return;
    	}
    }
    cout << "No" << endl;
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
