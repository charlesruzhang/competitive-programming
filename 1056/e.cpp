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
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int, greater<>> cnt;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (y > 0) cnt[y]++;
    }
    if (n == 1) {
        if (cnt[1] % 2) {
            cout << "Mimo" << endl;
        } else {
            cout << "Yuyu" << endl;
        }
        return;
    }
    for (auto [x, y] : cnt) {
        if (y % 2) {
            cout << "Mimo" << endl;
            return;
        }
    }
    cout << "Yuyu" << endl;
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
