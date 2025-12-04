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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int ans = d;
    for (int i = 0; i < d; i++) {
        if (s[i] == '1') {
            a -= c;
        } else {
            if (a >= b) {
                ans--;
            }
        }
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
