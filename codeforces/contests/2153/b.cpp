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
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i <= 30; i++) {
    	int a = ((x & (1<<i)) >= 1);
    	int b = ((y & (1<<i)) >= 1);
    	int c = ((z & (1<<i)) >= 1);
    	if (a + b + c == 2) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    cout << "YES" << endl;
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
