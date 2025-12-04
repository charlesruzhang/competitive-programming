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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;//c[i]
    }
    for (int i = 0; i < n; i++) {
    	cin >> a[i].second;//p[i]
    }
    sort(a.begin(), a.end(), [](pii x, pii y) {
    	auto [c1, p1] = x;
    	auto [c2, p2] = y;
    	return c1 / (1 - 1.0 / p1) < c2 / (1 - 1.0 / p2);
    });
    double ans = k / 1.0;
    double P = 1.0;
    double T = 0;
    for (int i = 0; i < n; i++) {
    	auto [c, p] = a[i];
    	T += c / P;
    	P *= p;
    	ans = min(ans, T + (k / P));
    }
    cout << setprecision(10) << ans << endl;
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
