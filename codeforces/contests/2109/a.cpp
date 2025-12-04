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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n - 1; i ++) {
    	if (a[i] == 0 && a[i+1] == 0) {
    		cout << "YES" << endl;
    		return;
    	}
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0) {
    		flag = 0;
    		break;
    	}
    }
    if (flag) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
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
