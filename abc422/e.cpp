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
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if (n <= 500) {
        for (int i = 0; i < n; i++) {
            map<pii, int> ma;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dx = x[j] - x[i];
                int dy = y[j] - y[i];
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0 && dy < 0) {
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                ma[{dx, dy}]++;
            }
            auto it = ma.begin();
            while (it != ma.end()) {
                if (it -> second >= n / 2) {
                    cout << "Yes" << endl;
                    auto [dx, dy] = it -> first;
                    ll dz = - (1ll * dy * x[i] - 1ll * dx * y[i]);
                    cout << dy << " " << -dx << " " << dz << endl;
                    return;
                }
                ++it;
            }
        }
        cout << "No" << endl;
        return;
    } else {
        for (int i = 0; i < 10; i++) {
            map<pii, int> ma;
            int flag = 1;
            int k = std::uniform_int_distribution<int>(0, n - 1)(rng);
            for (int j = 0; j < n; j++) {
                if (j == k) continue;
                int dx = x[j] - x[k];
                int dy = y[j] - y[k];
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0 && dy < 0) {
                    dy = -dy;
                }
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                ma[{dx, dy}]++;
                if (ma.size() > n / 2) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) continue;
            auto it = ma.begin();
            while (it != ma.end()) {
                if (it -> second >= n / 2) {
                    cout << "Yes" << endl;
                    auto [dx, dy] = it -> first;
                    ll dz = - (1ll * dy * x[k] - 1ll * dx * y[k]);
                    cout << dy << " " << -dx << " " << dz << endl;
                    return;
                }
                ++it;
            }
        }
        cout << "No" << endl;
        return;
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
