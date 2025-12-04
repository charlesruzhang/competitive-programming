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
    int a = 0;
    int b = 0;
    for (int i = 0; i < 2 * n; i++) {
    	int x;
    	cin >> x;
    	if (x) b++;
    	else a++;
    }
    int f = 0;
    if (a % 2 == 1) {
    	f = 1;
    }
    cout << f << " " << min(a, b) << endl;
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
