// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int x = c;
    int y = d;
    int z = n - c;
    int w = n - d;

    int xx = a;
    int yy = b;
    int zz = n - a;
    int ww = n - b;
    ll ans = 0;

    if (xx < x) {
    	ans = max(ans, x);
    }if (yy < y) {
    	ans = max(ans, y);
    }if (zz < z) {
    	ans = max(ans, z);
    }if (ww < w) {
    	ans = max(ans, w);
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
