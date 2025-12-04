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
set<int, greater<>> pvec;
const int maxN = 1e7+1;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.insert(i);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    auto it = pvec.lower_bound(m);
    int start = 1;
    ll ans = 0;
    while (it != pvec.end()) {
    	int p = *it;
    	int x = (n / p) * p;
    	if (x == 0) {
    		++it;
    		continue;
    	}
    	auto f = [&] (int end) {
    		ll q = p;
    		ll tot = 0;
    		while (q <= end) {
	    		int z = end / q;
	    		tot += 1ll * (z - 1) * z * q / 2;
	    		tot += 1ll * ((end % q) + 1) * z;
	    		q = q * p;
    		}
    		//cout << end << " " << p << " " << tot << endl;
    		return tot;
    	};
    	//cout << p << " " << x << " " << n << " " << m << endl;
    	if (x <= start) {
    		++it;
    		continue;
    	}
    	ans += (f(x - 1) - f(start - 1));
    	cout << start << " " << x - 1 << " " << ans << " " << p << endl;
    	start = x;
    	if (start == n) break;
    	++it;
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
