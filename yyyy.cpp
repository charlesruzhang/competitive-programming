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
vi primes;
int maxN = 2e5;
vi phi;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    phi.resize(maxN);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                phi[j] *= i - 1;
                phi[j] /= i;
            }
            phi[i] = i - 1;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    sieve();
    ll ans = 0;
    vl pref(n + 1);
    for (int i = 1; i <= n; i++) {
    	pref[i] = pref[i - 1] + phi[i];
    }
    for (int i = 1; i <= n; i++) {
    	ans += 2ll * i * pref[n / i] - 1;
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
