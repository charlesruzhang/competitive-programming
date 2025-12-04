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
    int L, R;
    cin >> L >> R;
    if (R == 0) {
    	cout << 0 << endl;
    	cout << 0 << endl;
    	return;
    }
    int n = R - L + 1;
    vi ans(n, -1);
    ll tot = 0;
    function <void(int, int)> f = [&] (int l, int r) {
        if (l > r) return;
        if (l == r) {
            ans[l - L] = ans[r - L] = l;
            tot += l;
            return;
        }
        int idx = -1;
        int T = 0;
        for (int i = 30; i >= 0; i--) {
            if (!((1 << i) & r)) {
                continue;
            }
            T |= (1 << i);
            if (!((1 << i) & l)) {
                idx = i;
                break;
            }
        }
        int top = T;
        int low = top - 1;
        while (top <= r && low >= l) {
            ans[top - L] = low;
            ans[low - L] = top;
            tot += 2ll * (top | low);
            top++;
            low--;
        }
        if (top > r) {
            f(l, low);
        } else {
            f(top, r);
        }
    };
    f(L, R);
    cout << tot << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
