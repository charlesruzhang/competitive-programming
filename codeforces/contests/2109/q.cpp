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
vi primes;
vi pvec;
vi mu;
const int maxN = 3e5+1;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    mu[1] = 1;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                }
                mu[j] *= -1;
            }
            mu[i] = -1;
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi ma(maxN), px(maxN);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	ma[a[i]] = 1;
    }
    for (int i = 1; i < maxN; i++) {
    	px[i] = px[i-1] + ma[i];
    }
    sort(a.begin(), a.end());
    vi cnt(maxN);
    ll ans = 0;
    vl pref(n+1);
    auto step = [&](int i) {
		for (int j = 1; j * j <= a[i]; j++) {
    		if (a[i] % j == 0) {
    			ans += mu[j] * cnt[j];
    			cnt[j]++;
    			if (j * j != a[i]) {
    				int l = a[i] / j;
    				ans += mu[l] * cnt[l];
    				cnt[l]++;
    			}
    		}
    	}
    };
    for (int i = 0; i < n; i++) {
    	step(i);
    	pref[i + 1] = ans;
    }
    cnt.assign(cnt.size(), 0);
    ans = 0;
    for (int i = n-1; i >= 0; i--) {
    	step(i);
    	pref[i] += ans;
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	tot += 1ll * (pref[i+1] - pref[i]) * px[a[i]];
    }
    cout << tot - ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
