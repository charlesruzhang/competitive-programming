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
    int p, n;
    cin >> p >> n;
    set<array<int, 4>> s;
    for (int i = 0; i < n; i++) {
        int p, x, y, t;
        cin >> p >> x >> y >> t;
        p--;
        s.insert({t, p, x, y});
    }
    auto it = s.begin();
    vvi ans(p, vi(p));
    while (it != s.end()) {
        auto [t, p, x, y] = *it;
        auto it2 = s.lower_bound({t - 10, -1, 0, 0});
        while (it2 != it) {
            auto [t2, p2, x2, y2] = *it2;
            if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) <= 1000000) {
                if (p > p2) swap(p, p2);
                ans[p][p2] = 1;
            }
            ++it2;
        } 
        ++it;
    }
    vector<pii> an;
    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            if (ans[i][j]) {
                an.push_back({i + 1, j + 1});
            }
        }
    }
    cout << an.size() << endl;
    for (int i = 0; i < an.size(); i++) {
        cout << an[i].first << " " << an[i].second << endl;
    }
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
