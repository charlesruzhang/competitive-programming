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
    vi a(n);
    for (int i = 0; i < n - 1; i++) {
    	cin >> a[i];
    }
    vvi dist(n, vi(n, 1e9));
    for (int i = 0; i < n - 1; i++) {
    	dist[i][i+1] = a[i];
    	dist[i][i] = 0;
    }
    dist[n-1][n-1] = 0;
    for (int k = 0; k < n; k++) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		cout << dist[i][j] << " ";
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
