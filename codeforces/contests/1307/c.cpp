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
    string s;
    cin >> s;
    int n = s.size();
    map<int, ll> ma;
    vi cnt(26);
    for (int i = 0; i < n; i++) {
        int z = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            ma[j * 26 + z] += cnt[j];
        }
        cnt[z]++;
    }
    auto it = ma.begin();
    ll ans = 0;
    while (it != ma.end()) {
        ans = max(ans, it -> second);
        ++it;
    }
    for (int i = 0; i < 26; i++) {
        ans = max(ans, (ll) cnt[i]);
    }
    cout << ans << endl;
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
