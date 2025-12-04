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
const int maxN = 2e5 + 1;
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
    vi used(n + 1);
    vi ans;
    int cur = 1;
    ans.push_back(1);
    used[1] = 1;

	vi primes;
	vi pvec;
    primes.assign(n + 1, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(n + 1));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < n + 1; j+=i) {
                primes[j] = 0;
            }
        }
    }
    for (int i = 2; i < n + 1; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
    int sz = pvec.size();
    for (int i = sz - 1; i >= 1; i--) {
    	int p = pvec[i];
    	for (int j = p; j <= n; j+=p) {
    		if (!used[j]) {
    			ans.push_back(j);
    			used[j] = 1;
    		}
    	}
    	for (int j = 0; j < 2; j++) {
    		if (2 * cur > n) break;
    		while (used[cur * 2]) {
    			cur++;
    			if (2 * cur > n) break;
    		}
    		if (2 * cur <= n) {
    			ans.push_back(2 * cur);
    			used[2 * cur] = 1;
    			cur ++;
    		}
    	}
    }
    while (2 * cur <= n) {
    	if (!used[2 * cur]) ans.push_back(2 * cur);
    	cur++;
    }
    assert(ans.size() == n);
    for (int x : ans) {
    	cout << x << " ";
    }
    cout << endl;
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
