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
const ll MAXX = 1e16;
int MOD = 0;
long long powMod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    MOD = s.size();
    int t = powMod(2, k);
    string ans;
    for (int i = 0; i < n; i++) {
    	ans += s[(i * 1ll * t) % MOD];
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
