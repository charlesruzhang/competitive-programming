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
vi pvec;
vi mu;
vi phi;
const int maxN = 1e5+1;
vvi facts;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    phi.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    facts.resize(maxN);
    mu[1] = 1;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            phi[i] = i - 1;
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                	phi[j] = phi[j / i] * i;
                } else {
                	phi[j] = phi[j / i] * (i - 1);
                }
                mu[j] *= -1;
            }
            mu[i] = -1;
        }
    }
    for (int i = 1; i < maxN; i++) {
    	for (int j = i; j < maxN; j+=i) {
    		facts[j].push_back(i);
    	}
    }
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    vi cnt(maxN);
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	ll tot = 0;
    	for (int j = 0; j < facts[x].size(); j++) {
    		int y = facts[x][j];
    		tot += 1ll * phi[y] * cnt[y] * (n - i - 1);
    		cnt[y]++;
    	}
    	ans += tot;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
