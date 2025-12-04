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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b = a;
    vi val(n);
    for (int i = 0; i < n; i++) {
    	while (b[i] % 2 == 0) {
    		b[i] /= 2;
    		val[i]++;
    	}
    }
    ll tot = 0; 
    vi p2(31, 1);
    for (int i = 1; i <= 30; i++) {
    	p2[i] = p2[i-1] * 2;
    }
    tot += p2[val[0]];
    vl right(n), left(n);
    right[0] = tot;
    left[n-1] = p2[val[n-1]];
    for (int i = 1; i < n; i++) {
    	if (b[i] != b[i-1] || a[i] < a[i-1]) {
    		right[i] = p2[val[i]]; 
    	} else {
    		right[i] = p2[val[i]] - p2[val[i-1] + 1] + 1;
    	}
    	tot += right[i];
    }
    for (int i = 0; i < n - 1; i++) {
    	if (b[i] != b[i+1] || a[i] < a[i+1]) {
    		left[i] = p2[val[i]]; 
    	} else {
    		left[i] = p2[val[i]] - p2[val[i+1] + 1] + 1;
    	}
    }
    ll ans = tot;
    for (int i = 1; i < n; i++) {
    	tot += left[i-1] + p2[val[i]];
    	tot -= right[i] + p2[val[i-1]];
    	ans = max(ans, tot);
    }
    if (ans >= k) {
    	cout << "YES" << endl;
    } else {
    	cout << "No" << endl;
    }
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
