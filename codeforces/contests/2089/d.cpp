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
    vi primes(n+1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= n; i++) {
    	if (primes[i]) {
    		for (int j = 2; j * i <= n; j++) {
    			primes[i*j] = 0;
    		}
    	}
    }
    int d = n / 2;
    vi x = {2, 1, 3, 4, 5};
    if (n <= 5) {
    	for (int i = 0; i < n; i++) {
    		cout << x[i] << " ";
    	}
    	cout << endl;
    	return;
    }
    int p = -1;
    for (int i = d; i <= n; i++) {
    	if (primes[i]) {
    		p = i;
    		break;
    	}
    }
    vi ans;
    int cur = 0;
    vi mark(n+1, 0);
    for (int i = 0; i < n; i++) {
    	int z = (i % 2) ? -1 : 1;
    	if (p+z*cur > n || p+z*cur < 1) {
    		break;
    	}
    	mark[p+z*cur] = 1;
    	ans.push_back(p + z * cur);
    	if (z == 1) {
    		cur++;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	if (!mark[i]) {
    		ans.push_back(i);
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
