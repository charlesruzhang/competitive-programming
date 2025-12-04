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
    vi maxx(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	maxx[i+1] = max(maxx[i], a[i]);
    }
    ll tot = 0;
    vl ans(n);
    for (int i = n-1; i>=0; i--) {
    	ans[i] = maxx[i+1] + tot;
    	tot += a[i];
    }
    reverse(ans.begin(), ans.end());
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
