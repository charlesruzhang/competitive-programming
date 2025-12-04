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
    int n, k;
    cin >> n >> k;
    vi l(n), r(n);
    for (int i = 0; i < n; i++) {
    	cin >> l[i];
    }

    for (int i = 0; i < n; i++) {
    	cin >> r[i];
    }
    ll ans = 0;
    vi v;
    for (int i = 0; i < n; i++) {
    	ans += max(l[i], r[i]);
    	v.push_back(min(l[i], r[i]));
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < k-1; i++) {
    	ans += v[i];
    }
    ans += 1;
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
