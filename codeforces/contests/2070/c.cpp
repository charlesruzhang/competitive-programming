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
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int l = 0;
    int r = 1e9;
    while (l < r) {
    	int m = (l + r) / 2;
    	int t = 0;
    	int count = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] > m) {
    			if (s[i] == 'B') {
    				if (!t) count++;
    				t = 1;
    			} else {
    				t = 0;
    			}
    		}
    	}
    	if (count <= k) {
    		r = m;
    	} else {
    		l = m + 1;
    	}
    }
    cout << l << endl;
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
