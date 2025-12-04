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
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vl c(n);
    for (int i = 0; i < n; i++) {
    	c[i] = 1ll * a[i] * b[i] / gcd(a[i], b[i]);
    }
    ll P = 0;
    for (int i = 0; i < n; i++) {
    	P = gcd(P, c[i]);
    	if (P != a[i]) {
    		cout << "NO" << endl;
    		return;
    	} 
    }
    ll S = 0;
    for (int i = n - 1; i >= 0; i--) {
    	S = gcd(S, c[i]);
    	if (S != b[i]) {
    		cout << "NO" << endl;
    		return;
    	} 
    }
    cout << "YES" << endl;
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
