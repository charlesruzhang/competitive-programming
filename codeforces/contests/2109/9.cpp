#include <bits/stdc++.h>
#include <bit>
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
int bit_length64(ll x) {
    if (x == 0) return 0;
    return 64 - __builtin_clzll(x);
}
void solve() {
    ll a;
    cin >> a;
    int cnt = bit_length64(a);
    ll tmp2 = (a << (cnt - 1));
    ll b = a ^ tmp2; 
    ll x, y;
    vector<tuple<ll, ll, ll>> ans;
    ll cur = a;
    for (int i = 0; i < cnt - 1; i++) {
    	ans.push_back({cur, cur, 1});
    	cur *= 2;
    }
    ans.push_back({cur, a, 0});

    egcd(a, b, x, y);
    y = -y;
    x = x % b;
    if (x < 0) x += b;
    y = y % a;
    if (y < 0) y += a;
    if (x % 2 == 0) {
    	x += b;
    	y += a;
    }
    int xl = bit_length64(x);
    int yl = bit_length64(y);
    cur = a;
    for (int i = 0; i < xl - 1; i++) {
    	ans.push_back({cur, cur, 1});
    	cur *= 2;
    }
    cur = b;
    for (int i = 0; i < yl - 1; i++) {
    	ans.push_back({cur, cur, 1});
    	cur *= 2;
    }
    ans.push_back({a, a, 0});
    ll prev = 0;
    for (int i = 0; i < xl; i++) {
    	if (x & (1ll << i)) {
    		ans.push_back({prev, (a << i), 1});
    		prev = prev + (a << i);
    	}
    }
    ll prev2 = 0;
    for (int i = 0; i < yl; i++) {
    	if (y & (1ll << i)) {
    		ans.push_back({prev2, (b << i), 1});
    		prev2 = prev2 + (b << i);
    	}
    }
    ans.push_back({prev, prev2, 0});
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	auto [f, s, t] = ans[i];
    	if (t) {
    		cout << f << " + " << s << endl;
    	} else {
    		cout << f << " ^ " << s << endl;
    	}
    }
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
