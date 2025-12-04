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
    if (n == 1) {
    	cout << 1 << endl;
    } else if (n == 2) {
    	cout << 9 << endl;
    } else if (n == 3) {
    	cout << 29 << endl;
    } else if (n == 4) {
    	cout << 56 << endl;
    } else {
    	int tot = 5 * ((n - 1) * n -1);
    	cout << tot << endl;
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
