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
    vvi a(n, vi(n));
    pii cent = {(n - 1) / 2, (n - 1) / 2};
    vector<pii> arr(4);
    arr[0] = {0, 1};
    arr[1] = {1, 0};
    arr[2] = {0, -1};
    arr[3] = {-1, 0};
    int tot = 0;
    int cur = 0;
    int now = 0;
    int amp = 1;
    int cur2 = 0;
    while (tot < n * n) {
        auto [x, y] = cent;
        //cout << x << " " << y << endl;
        a[x][y] = cur;
        x += arr[now].first;
        y += arr[now].second;
        cur2++;
        cent = {x, y};
        if (cur2 == amp) {
            cur2 = 0;
            now = (now + 1) % 4;
            if (now % 2 == 0) {
                amp++;
            } 
        }
        tot++;
        cur++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
