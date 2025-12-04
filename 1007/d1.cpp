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
    ll l, r;
    cin >> n >> l >> r;
    vi a(n+1);
    vi xo(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	xo[i] = xo[i-1] ^ a[i];
    }
    
    if (n % 2 == 0) {
    	a.push_back(xo[n/2]);
    	xo.push_back(xo[n] ^ a[n+1]);
    	n++;
    }
    if (l <= n) {
    	cout << a[l] << endl;
    	return;
    }
    int b = 0;
    vi arr;
    while (l > n) {
    	arr.push_back(l);
    	l /= 2;
    }
    int cur = xo[l];
    int tot = xo[n];
    for (int i = arr.size()-1; i >= 1; i--) {
    	if (cur && (arr[i] % 2 == 0)) {
    		b = 1;
    	} else {
    		b = 0;
    	}
    	cur = tot ^ b;
    }
    cout << cur << endl;
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
