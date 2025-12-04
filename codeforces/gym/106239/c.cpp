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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b;
    int f = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > 1) {
    		b.push_back(a[i]);
    	} else {
    		f = 1;
    	}
    }
    set<ll> S;
    ld cur = 1;
    n = b.size();
    for (int i = 1; i <= min(n, 30); i++) {
    	cur = 1;
    	for (int j = 0; j < i; j++) {
    		cur *= b[j];
    	}
    	for (int j = 0; j < n - i + 1; j++) {
    		if (cur <= 1e12) {
    			ll tot = 1;
    			for (int k = j; k < j + i; k++) {
    				tot *= b[k];
    			}
    			S.insert(tot);
    		}
    		cur /= b[j];
    		if (j + i < n) cur *= b[j + i];
    	}
    }
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	if (x == 1 && f) {
    		cout << "Yes" << endl;
    		continue;
    	}
    	if (S.find(x) == S.end()) {
    		cout << "No" << endl;
    	} else {
    		cout << "Yes" << endl;
    	}
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
