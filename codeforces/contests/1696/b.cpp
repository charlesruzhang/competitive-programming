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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt += (a[i] == 0 ? 1 : 0);
    }

    if (!cnt) {
    	cout << 1 << endl;
    	return;
    }
    if (cnt == n) {
    	cout << 0 << endl;
    	return;
    }
    int first = 1;
    int x = 1;
    for (int i = 0; i < n; i++) {
    	if (first && a[i]) {
    		x = 0;
    	} else if (a[i]) {
    		cout << 2 << endl;
    		return;
    	} else if (x == 0) {
    		first = 0;
    	}
    }
    cout << 1 << endl;
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
