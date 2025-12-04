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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int l1, l2, ln;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 1) {
    		l1 = i;
    	} else if (a[i] == 2) {
    		l2 = i;
    	} else if (a[i] == n) {
    		ln = i;
    	}
    }
    if (l1 < ln && ln < l2) {
    	cout << l1 + 1 << " " << l2 + 1 << endl;
    } else if (l2 < ln && ln < l1) {
    	cout << l1 + 1 << " " << l2 + 1 << endl;
    } else if (l2 < l1 && l1 < ln) {
    	cout << l1 + 1 << " " << ln + 1 << endl;
    } else if (ln < l1 && l1 < l2) {
    	cout << l1 + 1 << " " << ln + 1 << endl;
    } else if (ln < l2 && l2 < l1) {
    	cout << l2 + 1 << " " << ln + 1 << endl;
    } else {
    	cout << l2 + 1 << " " << ln + 1 << endl;
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
