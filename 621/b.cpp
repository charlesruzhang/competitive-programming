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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int y = (x - 1) / a.back() + 1;
    if (y == 1) {
    	int f = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] == x) {
    			f = 1;
    			break;
    		}
    	}
    	if (f) {
    		cout << 1 << endl;
    	} else {
    		cout << 2 << endl;
    	}
    	return;
    }
    cout << y << endl;
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
