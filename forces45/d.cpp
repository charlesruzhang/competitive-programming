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
    vvi cnt(4, vi(2 * n + 1));
    cnt[3][n] = 1;
    int cur = n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	cur += ((a[i] % 2) ? 1 : -1);
    	cnt[i % 4][cur]++;
    	if (cur) ans += cnt[(i + 3) % 4][cur-1];
    	if (cur < 2 * n) ans += cnt[(i + 3) % 4][cur+1];
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
