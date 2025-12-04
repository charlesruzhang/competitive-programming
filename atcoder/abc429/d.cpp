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
    int n, c;
    ll m;
    cin >> n >> m >> c;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl b(2 * n);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
    	b[i] = a[i];
    	b[n + i] = m + b[i];
    }
    ll ans = 0;
    int prev = c - 1;
    for (int i = 0; i < n; i++) {
    	int end = prev;
    	while (end < 2 * n && (end - i + 1 < c) || b[end] == b[end + 1]) {
    		end++;
    	}
    	ans += 1ll * (end - i + 1) * (b[i] - (i ? b[i-1] : b[n - 1] - m));
    	prev = end;
    }
    cout << ans << endl;
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
