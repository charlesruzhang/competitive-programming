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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
        s.insert({a[i].second, a[i].first});
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int last = -1;
        while (1) {
            auto it = s.lower_bound({last, -1});
            while (it != s.end() && (*it)[1] < last) {
                ++it;
            }
            if (it == s.end()) {
                break;
            }
            last = (*it)[0];
            ans++;
            s.erase(it);
        }
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
