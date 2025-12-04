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
    int minn = 1e9 + 7;
    int idx = -1;
    int flag = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (minn > a[i]) {
    		minn = a[i];
    		idx = i;
    	}
    	if (i && a[i] != a[i-1]) {
    		flag = 1;
    	}
    }
    if (n >= 30) {
    	if (flag) {
    		a[0]--;
    		int x = count(a.begin(), a.end(), a[0]);
    		if (x == n) {
    			cout << 1ll * n * a[0] << endl;
    		} else {
    			cout << -1 << endl;
    		}
    	} else {
    		cout << 1ll * n * a[0] << endl;
    	}
    	return;
    }
    if (n == 2) {
    	if ((a[0] + a[1]) % 2) {
    		cout << a[0] + a[1] - 1 << endl;
    	} else {
    		cout << a[0] + a[1] << endl;
    	}
    	return;
    }
    swap(a[idx], a[0]);
	ll maxx = 0;
    auto check = [&] () {
    	maxx = 0;
	    ll tot = 1;
	    for (int i = 1; i < n; i++) {
			for (int j = 2; j < n; j++) {
				if ((a[i] % j) != (a[0] % j)) {
					return true;
				}
			}
	    }
	    ll summ = accumulate(a.begin(), a.end(), 0ll);
		return (summ % n > 0);
    };
    
	ll summ = accumulate(a.begin(), a.end(), 0ll);
    if (check()) {
		a[0]--;
		summ--;
	} else {
		cout << summ << endl;
		return;
	}
	if (check()) {
		cout << -1 << endl;
	} else {
	    cout << summ << endl;
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
