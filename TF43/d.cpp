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
vi ans(1e6+1, 1);
vl pref(1e6+2);
vi primes;
vi pvec;
const int maxN = 1e6+5;
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
void comp() {
	sieve();
	for (int i = 1; i <= 1e6; i++) {
		ans[i] = i;
	}
	ans[1] = 1;
	for (int i = 2; i <= 1e6; i++) {
		if (primes[i]) {
			ans[i] = i - 1;
			for (int j = i * 2; j <= 1e6; j+=i) {
				ans[j] = 1ll * ans[j] * (i - 1) / i;
			}
		}
	}
	for (int i = 1; i <= 1e6; i++) {
		pref[i+1] = pref[i] + (ans[i] - 1);
		//cout << i << " " << ans[i] << endl;
	}
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << pref[r+1] - pref[l] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
