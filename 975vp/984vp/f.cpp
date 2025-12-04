#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
const int MOD = 1e9+7;
void solve() {
    ll l, r;
    cin >> l >> r;
    ll dp[62][2][5];
    function <ll(int, int, int, vi&)> g = [&](int pos, int tight, int num, vi& digits) {
        if (pos == digits.size()) return (num == 4) ? 0ll : 1ll;
        if (dp[pos][tight][num] != -1) return dp[pos][tight][num];

        ll res = 0;
        int lim = (tight) ? digits[pos] : 1;
        for (int i = 0; i <= lim; i++) {
            int nnum = (i != 0) ? num+1 : num;
            res ^= g(pos+1, tight && (i == lim), min(4, nnum), digits);
        } 
        return dp[pos][tight][num] = res;
    };
    function <ll(ll)> f = [&](ll x) {
        int idx = 0;
        vector<int> digits;
        while (x) {
            digits.push_back(x % 2);
            x /= 2;
            idx++;
        }
        reverse(digits.begin(), digits.end());
        memset(dp, -1, sizeof(dp));
        return g(0,1,0,digits);
    };
    ll ans = f(r) - f(l-1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}