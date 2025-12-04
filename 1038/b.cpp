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
    vvi a(n, vi(4));
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4; j++) {
    		cin >> a[i][j];
    	}
    	if (a[i][2] > a[i][0]) {
    		tot += a[i][2] - a[i][0];
    	}
    	if (a[i][3] < a[i][1]) {
    		tot += a[i][1] - a[i][3] + min(a[i][0], a[i][2]);
    	}
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
