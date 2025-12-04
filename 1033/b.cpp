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
    int n, s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	int X, Y;
    	cin >> X >> Y;
    	if (x < 0) {
    		x = -x;
    		y = -y;
    	}
    	if (y == 1 && X == Y) {
    		cnt++;
    	} else if (y == -1 && X + Y == s) {
    		cnt++;
    	} 
    }
    cout << cnt << endl;
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
