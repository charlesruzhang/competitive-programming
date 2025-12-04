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
    int G = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	G = gcd(G, a[i]);
    }
    if (G == 1) {
    	cout << 0 << endl;
    	return;
    }
    G = 0;
    for (int i = 0; i < n-1; i++) {
    	G = gcd(G, a[i]);
    }
    G = gcd(G, gcd(a[n-1],n));
    if (G == 1) {
    	cout << 1 << endl;
    	return;
    }
    G = 0;
    for (int i = 0; i < n; i++) {
    	if (i != n - 2) G = gcd(G, a[i]);
    }
    G = gcd(G, gcd(a[n-2],n - 1));
    if (G == 1) {
    	cout << 2 << endl;
    	return;
    }
    cout << 3 << endl;
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
