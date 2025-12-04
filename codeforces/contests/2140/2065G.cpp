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
vi lp;
const int maxN = 2e5 + 1;
void sieve() {
    primes.assign(maxN, 1);
    lp.resize(maxN);
    for (int i = 1; i < maxN; i++) {
    	lp[i] = i;
    }
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
                lp[j] = min(lp[j], i);
            }
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
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cnt[a[i]]++;
    }
    ll ans = 0;
    ll summ = 0;
    ll ans2 = 0;
    for (int i = 2; i <= n; i++) {
    	if (primes[i]) {
    		summ += cnt[i];
    		ans2 -= 1ll * cnt[i] * cnt[i];
    	}
    	int x = lp[i];
    	int y = i / x;
    	if (primes[y]) {
    		if (x == y) {
    			ans += 1ll * cnt[x] * cnt[i];
    		} else {
    			ans += 1ll * cnt[y] * cnt[i];
    			ans += 1ll * cnt[x] * cnt[i];
    		}
    		ans += 1ll * cnt[i] * (cnt[i] + 1) / 2;
    	}
    }
    ans2 += summ * summ;
    ans += ans2 / 2;	
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
