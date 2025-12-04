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
    vl a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    string ss;
    cin >> ss;
    vi s(n);
    for (int i = 0; i < n; i++) {
    	s[i] = ss[i] - '0';
    }
    ll ans = 0;
    for (int i = 59; i >= 0; i--) {
    	int l = -1;
   		int cum = 0;    		
    	for (int j = 0; j < n; j++) {
    		int x = a[j] >> i & 1;
    		int y = b[j] >> i & 1;
    		if (x == y) {
    			cum ^= x;
    		} else {
    			l = j;
    		}
    	}
		if (l == -1) {
			ans += ((ll) cum) << i;
		} else {
			ans += ((ll) s[l]) << i;

			cum ^= s[l];
			ll z = a[l] ^ b[l];
			if (cum) {
				if (a[l] >> i & 1) {
					b[l] = a[l];
				} else {
					a[l] = b[l];
				}
			} else {
				if (a[l] >> i & 1) {
					a[l] = b[l];
				} else {
					b[l] = a[l];
				}
			}
			for (int j = 0; j < l; j++) {
				int x = a[j] >> i & 1;
				int y = b[j] >> i & 1;
				if (x == y) continue;
				if (x) {
					a[j] ^= z;
				} else {
					b[j] ^= z;
				}
			}

		}
    }
    cout << ans << endl;
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
