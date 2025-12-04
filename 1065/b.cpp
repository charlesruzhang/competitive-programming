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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++) {
    	if (a[i] == -1) {
    		a[i] = 0;
    	}
    }
    if (a[0] == a[n-1] && a[0] == -1) {
    	a[0] = a[n-1] = 0;
    } else if (a[0] == -1) {
    	a[0] = a[n -1];
    } else if (a[n-1] == -1) {
    	a[n-1] = a[0];
    }
    cout << a[n-1] - a[0] << endl;
    for (int x : a) {
    	cout << x << " ";
    }
    cout << endl;
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
