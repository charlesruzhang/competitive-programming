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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi v(n, -1);
    int flag = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        if (n % 2) {
            if (a[0] == 1 + n / 2) {
                cout << 2 << endl;
                return;
            } else {
                cout << 0 << endl;
                return;
            }
        } else {
            if (a[0] == 1 + n / 2 || a[0] == 1 + (n - 1) / 2) {
                cout << 1 << endl;
                return;
            } else {
                cout << 0 << endl;
                return;
            }
        }
        //cout << 2 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) {
            if (abs(a[i] - a[i-1]) >= 2) { 
                cout << 0 << endl;
                return;
            }
            if (a[i] > a[i-1]) {
                if (v[i-1] == 1) {
                    cout << 0 << endl;
                    return;
                }
                v[i] = v[i-1] = 0;
            } else {
                if (v[i-1] == 0) {
                    cout << 0 << endl;
                    return;
                }
                v[i] = v[i-1] = 1;
            }
        } else {
            if (v[i-1] != -1) {
                v[i] = 1 - v[i-1];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == -1) {
            assert(a[i] == a[i+1]);
            v[i] = 1 - v[i+1];
        }
    }
    int tot = 1;
    for (int i = 1; i < n; i++) {
        tot += (v[i] == 1 ? 1 : 0);
    }
    if (tot != a[0]) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
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
