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
    vector<int> prime(n+1, 1);
    prime[0] = prime[1] = 0;
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; i++) {
    	if (prime[i]) {
    		for (int j = 2 * i; j <= n; j+=i) {
    			prime[j] = 0;
    			phi[j] /= i;
    			phi[j] *= i - 1;
    		}
    		phi[i] = i - 1;
    	}
    }
    vl pref(n+1);
    for (int i = 1; i <= n; i++) {
    	pref[i] = pref[i-1] + phi[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
    	ans += 1ll * i * (2 * pref[n / i] - 1);
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
