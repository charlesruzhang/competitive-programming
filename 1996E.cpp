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
    string s;
    cin >> s;
    int n = s.size();
    int tot = n;
    vl v(2 * n + 1);
    v[n] = 1;
    ll ans = 0;
    int INF = 1e9 + 7;
    for (int i = 0; i < n; i++) {
    	int z = (s[i] == '0') ? 1 : -1;
    	tot += z;
    	ans += 1ll * v[tot] * (n - i); 
    	ans = ans % INF;
    	v[tot] += (i + 2);
    }
    cout << ans << endl;
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
