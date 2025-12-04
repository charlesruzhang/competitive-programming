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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl arr(n+1, -1e12);
    ll cnt = 1;
    for (int i = 1; i < n; i++) {
    	if (a[i] == a[i-1]) {
    		cnt++;
    	} else {
    		arr[a[i-1]] = max(arr[a[i-1]], cnt);
    		cnt = 1;
    	}
    }
    arr[a[n-1]] = max(arr[a[n-1]], cnt);
    ll ans = MAXX;
    for (int i = 1; i <= n; i++) {
    	ans = min(ans, 1ll * (n - arr[i]) * i);
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
