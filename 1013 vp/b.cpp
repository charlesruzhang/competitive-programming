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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int minn = 1e9 + 7;
    int cnt = 0;
    int ans = 0;
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < n; i++) {
    	minn = min(minn, a[i]);
    	cnt++;
    	if (1ll * minn * cnt >= x || a[i] >= x) {
    		cnt = 0;
    		ans++;
    		minn = 1e9 + 7;
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
