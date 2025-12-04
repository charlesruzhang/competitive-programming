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
    for (int i = 0; i < n - 1; i++) {
    	if (a[i] != b[i] && ((a[i] ^ b[i+1]) != b[i]) && ((a[i] ^ a[i+1]) != b[i])) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    if (a[n-1] != b[n-1]) {
    	cout << "NO" << endl;
    } else {
    	cout << "Yes" << endl;
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
