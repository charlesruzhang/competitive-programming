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
    ll m;
    cin >> n >> m;
    vl a(n), b(n);
    ll minn = 1e17;
    int idx = -1;
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    	if (minn > a[i] + b[i]) {
    		minn = a[i] + b[i];
    		idx = i;
    	}
    }
    sort(a.begin(), a.end());
    ll ans1 = 0;
    ll x = m;
    for (int i = 0; i < n; i+=2) {
    	if (i + 1 < n && a[i] + a[i + 1] < minn) {
    		x -= a[i];
    		if (x < 0) {
    			break;
    		}
    		ans1++;
    		x -= a[i+1];
    		if (x < 0) {
    			break;
    		}
    		ans1 ++;
    	}
    }
    if (x > 0) {
    	ans1 += 2 * (x / minn);
    }
    ll ans2 = 0;
    ll y = m;
    if (a[0] > m) {
    	cout << 0 << endl;
    	return;
    }
    ans2++;
    y -= a[0];
    for (int i = 1; i + 1 < n; i+=2) {
    	if (a[i] + a[i + 1] < minn) {
    		y -= a[i];
    		if (y < 0) {
    			break;
    		}
    		ans2++;
    		y -= a[i+1];
    		if (y < 0) {
    			break;
    		}
    		ans2++;
    	}
    }
    if (y > 0) {
    	ans2 += 2 * (y / minn);
    }
    cout << max(ans1, ans2) << endl;
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
