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
    vi G(n), H(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	g = gcd(g, a[i]);
    	G[i] = g;
    }
    int h = 0;
    for (int i = n - 1; i >= 0; i--) {
    	h = gcd(h, a[i]);
    	H[i] = h;
    }
    ll ans = 0;
    ans += G[n-1];
    for (int i = 1; i < n - 1; i++) {
    	ans += min(G[i], H[i]);
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
