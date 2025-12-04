// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
    ll m;
    cin >> n >> m;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    int j = 0;
    ll t = 0;
    vl ans(252001);
    int z = 0;
    vi seen(10, -1);
    seen[0] = 0;
    ll cur = 0;
    int period = 0;
    int P = 0;
    int off = 0;
    while (1) {
    	ll prev = period * 2520;
    	while (cur - prev < 2520) {
	    	if ((cur + 1) % a[j] == b[j]) {
	    		z++;
	    	} else {
	    		z = 0;
	    		cur = cur + 1;
	    		ans[cur] = t + 1;
	    	}
	    	j = (j + 1) % n;
	    	t++;
	    	if (cur == m) {
	    		cout << t << endl;
	    		return;
	    	}
	    	if (z >= n) {
	    		cout << -1 << endl;
	    		return;
	    	}
	    }
	    period++;
	    if (seen[j] != -1) {
	    	off = seen[j] * 2520;
	    	P = (period - seen[j]) * 2520;
	    	break;
	    }
	    seen[j] = period;
    }
    
    ll x = (m - off) / P;
    ll y = (m - off) % P;
    //cout << ans[off] << " " << x * (ans[off + P] - ans[off]) << " " << (ans[y + off] - ans[off]) << endl;
    cout << x * (ans[off + P] - ans[off]) + ans[y + off] << endl;
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
