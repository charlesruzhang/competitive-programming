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
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y) {
    	swap(x, y);
    	swap(a, b);
    }
    int z = (k - a) / x + 1;
    if (k < a) {
    	z = 0;
    } else {
    	k -= z * x;	
    }
    //cout << z << " " << k << endl;
    if (k >= b) {
    	int yy = (k - b) / y + 1;
    	z += yy;
    }
    cout << z << endl;
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
