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
    string s;
    cin >> s;
    int n = s.size();
    ll tot = 0;
    int cur = 0;
    for (int i = n - 1; i>= 0; i--) {
    	int x = (s[i] - '0' + 10 - cur) % 10;
    	tot += x;
    	cur = (cur + x ) %10;

    }
    tot += n;
    cout << tot << endl;
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
