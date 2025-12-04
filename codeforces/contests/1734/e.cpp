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
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vvi a(n, vi(n));
    for (int i = 1; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		int off = (i + j) % n;
    		a[i][j] = (a[i-1][j] + off) % n;
    	}
    }
    for (int i = 0; i < n; i++) {
    	int off = b[i] + n - a[i][i];
    	for (int j = 0; j < n; j++) {
    		a[i][j] = (a[i][j] + off) % n;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cout << a[i][j] << " ";
    	}
    	cout << endl;
    }
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
