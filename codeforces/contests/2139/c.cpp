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
    ll a, b;
    cin >> a >> b;
    if ((a * b) % 2 == 0) {
    	if ((a * b) % 4 != 0 || b % 2) {
    		cout << -1 << endl;
    		return;
    	} else {
    		cout << (a * b / 2) + 2 << endl;
    	}
    } else {
    	cout << a * b + 1 << endl;
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
