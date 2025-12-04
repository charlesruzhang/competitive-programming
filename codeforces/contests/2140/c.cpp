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
    ll ans = 0;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (i % 2) {
    		ans -= a[i]; 
    	} else {
    		ans += a[i];
    	}
    }
    int minn = 1e9+1;
    ll ans2 = n - 1 - ((n % 2 == 0) ? 1 : 0);
    for (int i = 0; i < n; i++) {
    	if (i % 2 == 0) {
    		minn--;
    		minn = min(minn, a[i]);
    	} else {
    		ans2 = max(ans2, (a[i] - minn) * 2ll + 1);
    	}
    }
    int minn2 = 1e9+ 1;
    for (int i = n - 1; i >= 0; i--) {
    	if (i % 2 == 0) {
    		minn2--;
    		minn2 = min(minn2, a[i]);
    	} else {
    		ans2 = max(ans2, (a[i] - minn2) * 2ll + 1);
    	}
    }
    ans += ans2;
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
