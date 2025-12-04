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
    if (n % 2 == 1) {
    	cout << "NO" << endl;
    	if (n <= 5) {
    		cout << "NO" << endl;
    	} else {
    		vi p(n+1, -1);
    		int x = n - 1;
    		int y = n;
    		if ((x & (x - 1)) == 0) {
    			y = x - 1;
    		}
			p[y] = y - 2;
			p[y-2] = 1;
			p[1] = y;
			p[y-3] = y - 1;
			p[y-1] = y - 3;
    		for (int i = 1; i <= n; i++) {
				if (p[i] == -1) {
					if (i & 1) {
						p[i] = i - 1;
					} else {
						p[i] = i + 1;
					}
				}
			}
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) {
				cout << p[i] << " ";
				assert(p[i] & i);
			}
			cout << endl;
    	}
    } else {
    	cout << "YES" << endl;
    	vi p(n+1, -1);
    	int x = 1;
    	while (x <= n) {
    		x *= 2;
    	}
    	x--;
    	for (int i = n; i >= 1; i--) {
    		while (x - i > n || p[x - i] != -1) {
    			x /= 2;
    		}
    		p[x - i] = i;
    	}
    	for (int i = 1; i <= n; i++) {
    		cout << p[i] << " ";
			assert((p[i] & i) == 0);
    	}
    	cout << endl;

    	if ((n & (n - 1)) == 0) {
    		cout << "NO" << endl;
    		return;
    	}
    	cout << "YES" << endl;
    	vi p2(n+1, -1);
    	p2[n] = n - 2;
    	p2[n-2] = n;
    	p2[n-1] = 1;
    	p2[1] = n - 1;
		for (int i = 1; i <= n; i++) {
			if (p2[i] == -1) {
				if (i & 1) {
					p2[i] = i - 1;
				} else {
					p2[i] = i + 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << p2[i] << " ";
			assert(p2[i] & i);
		}
		cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
