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
ll egcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool crt(ll r1, ll m1, ll r2, ll m2, ll &t0, ll &lcm) {
    ll x, y;
    ll g = egcd(m1, m2, x, y);
    ll diff = r2 - r1;
    if (diff % g != 0) return false;

    lcm = m1 / g * m2;
    ll m2g = m2 / g;

    ll k = (diff / g) % m2g;
    if (k < 0) k += m2g;
    x %= m2g; if (x < 0) x += m2g;
    k = (k * x) % m2g;

    t0 = r1 + m1 * k;
    t0 %= lcm; if (t0 < 0) t0 += lcm;
    return true;
}

void solve() {
    int n, x, y, vx, vy;
    cin >> n >> x >> y >> vx >> vy;
    int g = __gcd(vx, vy);
    vx /= g;
    vy /= g;
    int gx = __gcd(n, vx);
    int gy = __gcd(n, vy);
    if (__gcd(gx, n-x) != gx || __gcd(gy, n-y) != gy) {
    	cout << -1 << endl;
    	return;
    }
    ll xx, yx;
    ll dx = egcd(vx, n, xx, yx);
    assert(dx == gx);
    xx *= (n - x) / dx;

    ll xy, yy;
    ll dy = egcd(vy, n, xy, yy);
    assert(dy == gy);
    xy *= (n - y) / dy;
    
    ll t, tmp;
    if (!crt(xx, n / dx, xy, n / dy, t, tmp)) {
    	cout << -1 << endl;
    	return;
    }
    __int128 X = (__int128)vx * t + x;
    __int128 Y = (__int128)vy * t + y;
    ll XX = X / n;
    ll YY = Y / n;;
    ll ans = XX - 1 + YY - 1 + (XX + YY) / 2 + abs(XX - YY) / 2;
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
