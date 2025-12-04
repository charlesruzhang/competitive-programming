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
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    for (int i = 19; i >= 0; i--) {
    	vi A(n), B(n);
    	ll tot = 0;
    	for (int j = 0; j < n; j++) {
    		A[j] = ((a[j] >> i) & 1 ? 1 : 0);
    		B[j] = ((b[j] >> i) & 1 ? 1 : 0);
    		tot += A[j] + B[j];
    	}

		if (tot % 2 == 0) {
			continue;
		}
    	for (int j = n - 1; j >= 0; j--) {
    		if (A[j] != B[j]) {
    			if (j % 2) {
    				cout << "Mai" << endl;
    				return;
    			} else {
    				cout << "Ajisai" << endl;
    				return;
    			}
    		}
    	}
    }
    cout << "Tie" << endl;
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
