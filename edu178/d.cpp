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
int maxN = 7e6;
vector<int> primes(maxN, 1);
vi pp;
vl psum;
void sieve() {
	for (int i = 2; i < maxN; i++) {
		if (primes[i]) {
			for (int j = 2 * i; j < maxN; j+=i) {
				primes[j] = 0;
			}
		}
	}
	for (int i = 2; i < maxN; i++) {
		if (primes[i]) {
			pp.push_back(i);
		}
	}
	psum.push_back(0);
	for (int i = 0; i < pp.size(); i++) {
		psum.push_back(psum.back() + pp[i]);
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
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    int cur = n;
    int ans = 0;
    while (summ < psum[cur]) {
    	cur --;
    	summ -= a[ans];
    	ans++;
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
