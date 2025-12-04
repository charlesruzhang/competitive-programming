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
    int k;
    cin >> k;
    int n = (1 << k);
    vi a(n);
    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    ll ans = 0;
    ans = 1ll * n * (n - 1) / 2;
    for (int i = 1; i <= n; i++) {
    	ans -= 1ll * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans * n / 2 << endl;
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
