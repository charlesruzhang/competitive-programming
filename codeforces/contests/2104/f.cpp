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
    ll dp[10][2][10][3];
    function <ll(int, int, int, int, vi&)> g = [&](int pos, int tight, int maxx, int first, vi& digits) {
        if (dp[pos][tight][maxx][first] != -1) return dp[pos][tight][maxx][first];
 
        ll res = 0;
        int lim = (tight) ? digits[pos] : 9;
        for (int i = 0; i <= lim; i++) {

        	if (i != 0 && i < maxx) continue;
        	if (i == 0 && i < maxx && !first) continue;
        	if (pos == digits.size() - 2) {
        		if (tight && i == lim) {
        			res += digits.back() + 1;
        		} else {
        			res += 10;
        		}
        		continue;
        	}
        	int nexmin = (first == 1 && i == 0) ? 0 : maxx;

        	int nfirst;
        	if (first) {
        		nfirst = 2;
        	} else if (!first && i != 0) {
        		nfirst = 1;
        	} else {
        		nfirst = 0;
        	}
            res += g(pos+1, tight && (i == lim), nexmin, nfirst, digits);
        } 
        return dp[pos][tight][maxx][first] = res;
    };
    function <ll(ll)> f = [&](ll x) {
        int idx = 0;
        vector<int> digits;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
            idx++;
        }
        reverse(digits.begin(), digits.end());
        memset(dp, -1, sizeof(dp));
        return g(0,1,0,0,digits);
    };
    cout << f(n) - 1 << endl;
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
