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
    vl x(n), y(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }
    ll prev = y[0];
    ll A = x[0] * y[0];
    int ans = n;
    for (int i = 1; i < n; i++) {
    	ll G = prev * y[i] / gcd(prev, y[i]);
    	ll gx = G / prev;
    	ll gy = G / y[i];
    	ll B = gcd(A, x[i] * y[i]);
    	if (B % G == 0) {
    		ans--;
    		A = B;
    		prev = G;
    	} else {
    		A = x[i] * y[i];
    		prev = y[i];
    	}
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
