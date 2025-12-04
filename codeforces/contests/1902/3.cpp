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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll, int> m;
    ll maxx = -1000000007;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	m[a[i]] = 1;
    	maxx = max(maxx, a[i]);
    	if (i > 0) b[i] = a[i] - a[i-1];
    }
    if (n == 1) {
    	cout << 1 << endl;
    	return;
    }
    if (n == 2) {
    	cout << 3 << endl;
    	return;
    }
    ll g = abs(b[1]);
    for (int i = 1; i < n; i++) {
    	g = gcd(g, abs(b[i]));
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	ans += (maxx - a[i]) / g;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	cur ++;
    	if (m[maxx - g * (i+1)] == 0) {
    		break;
    	}
    }
    ans += cur;
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
