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
ll query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	ll res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    ll tot = query(1, n);
    auto s1 = [&] (ll x) {
    	return 1ll * (x - 1) * x / 2;
    };
    auto s2 = [&] (ll x) {
    	return (1 + sqrt(8 * x + 1)) / 2;
    };
    int l = 1;
    int r = n;
    int ii, jj, kk;
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	ll res1 = query(l, m);
    	if (res1 == 0) {
    		l = m;
    		continue;
    	}
    	if (res1 == tot) {
    		r = m;
    		continue;
    	}
    	ll res2 = query(l, m-1);
    	ll diff = res1 - res2;
    	int piv = m - diff;
    	if (s1(m - diff)==res1) {
    		ii = piv;
    		ll res3 = query(ii, n);
    		ll res4 = query(ii+1, n);
    		diff = res3 - res4;
    		jj = ii + diff + 1;
    		kk = jj + s2(res3 - s1(jj - ii)) - 1;
    	} else {
    		jj = piv;
    		ii = jj - s2(res1 - s1(m-jj+1));
    		ll res3 = query(jj, n);
    		kk = jj + s2(res3) - 1;
    	}
    	cout << "! " << ii << " " << jj << " " << kk << endl;
    	return;
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
