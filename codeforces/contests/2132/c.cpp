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
    int x = n;
    int cnt = 0;
    ll tot = 0;
    while (x) {
    	int y = x % 3;
    	ll cur = 1;
    	for (int i = 0; i < cnt; i++) {
    		cur *= 3;
    	}
    	tot += y * (3 * cur + cnt * cur / 3);
    	cnt++;
    	x /= 3;
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
