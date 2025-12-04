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
	int summ = 0;
    for (int i = 0; i < 9; i++) {
    	int x;
    	cin >> x;
    	summ += x;
    }
    for (int i = 0; i < 8; i++) {
    	int x;
    	cin >> x;
    	summ -= x;
    }
    cout << summ + 1<< endl;
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
