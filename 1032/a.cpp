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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int diff = a[n-1] - a[0];
    int minn = min(abs(s - a[0]), abs(s - a[n-1]));
    cout << diff + minn << endl;
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
