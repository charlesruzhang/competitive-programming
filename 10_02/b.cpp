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
    int n, s;
    cin >> n >> s;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    if (a[0] == 0) {
    	cout << "NO" << endl;
    	return;
    }
    if (a[s-1] == 1) {
    	cout << "YES" << endl;
    	return;
    }
    if (b[s-1] == 0) {
    	cout << "NO" << endl;
    	return;
    }
    for (int i = s; i < n; i++) {
    	if (a[i] && b[i]) {
    		cout << "YES" << endl;
    		return;
    	}
    }
    cout << "NO" << endl;
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
