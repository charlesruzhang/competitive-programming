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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b = a;
    ll ans = 0;
    if (a[0] > a[1]) {
    	ans += a[0] - a[1];
    	a[0] = a[1];
    }
    for (int i = 2; i < n; i+=2) {
    	if (a[i] + a[i-2] > a[i-1]) {
    		int diff =  a[i] + a[i-2] - a[i-1];
    		ans += diff;
    		a[i] = max(0, a[i] - diff);
    	}
    }
    if (n % 2 == 0 && a[n-2] > a[n-1]) {
    	ans += a[n-2] - a[n-1];
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
