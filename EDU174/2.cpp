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
    vi a(n);
    vi cou(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cou[a[i]]++;
    }
    int ml = 0;
    int s = 0;
    int t = 0;
    int cur = 0;
    int cus = 0;
    for (int i = 0; i < n; i++) {
        if (cou[a[i]] == 1) {
            cur++;
            if (cur == 1) cus = i;
        } else {
            if (cur > ml) {
                ml = cur;
                s = cus;
                t = i - 1;
                cur = 0;
            }
        }
    }
    if (cur > ml) {
        ml = cur;
        s = cus;
        t = n - 1;
    }
    if (ml == 0) {
        cout << 0 << endl;
        return;
    }
    cout << s+1 << " " << t+1 << endl;
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
