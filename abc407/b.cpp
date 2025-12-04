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
    int x, y;
    cin >> x >> y;
    int a = 0;
    for (int i = 1 ;i <= 6; i++) {
    	for (int j = 1; j <= 6; j++) {
    		if (i + j >= x || abs(i - j) >= y) {
    			a++;
    		}
    	}
    }
    cout << setprecision(10) << (double) a / 36 << endl;
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
