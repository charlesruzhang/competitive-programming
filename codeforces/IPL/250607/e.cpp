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
void solve() {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) 
    	cin >> a[i];
   	vl b(n, -1);
   	for (int i = 1; i < n ; i++) {
   		ll z = a[i];
   		while (z >= a[i-1]) {
   			b[i]++;
   			z /= 2;
   		}
   	}
    ll tot = 0;
    vl c(n);
   	for (int i = 1; i < n; i++) {
   		ll z = a[i];
   		int f = c[i-1] - max(0ll, b[i]);
   		c[i] = max(f, 0);
   		while (z < a[i-1]) {
   			z *= 2;
   			c[i]++;
   		}
   	}
   	for (int i = 0; i < n; i++) {
   		tot+=c[i];
   	}
   	cout << tot << endl;
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
