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
int maxN = 1e7;
vector<int> primes(maxN+1, 1);
vector<int> p;
void sieve() {
	for (int i = 2; i < maxN + 1; i++) {
		if (primes[i]) {
			for (int j = 2 * i; j < maxN + 1; j+= i) {
				primes[j] = 0;
			}
			p.push_back(i);
		}
	}
}
void solve() {
    int n; 
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < p.size() && p[i] <= n; i++) {
    	ans += n / p[i];
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
