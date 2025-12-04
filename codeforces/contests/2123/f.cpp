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
vi primes;
vi pvec;
const int maxN = 2e5;
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
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	a[i] = i;
    }
    vi mark(n+1);
    for (int i = n / 2; i >= 2; i--) {
    	if (!primes[i]) continue;
    	if (mark[i]) continue;
    	int prev = i;
    	mark[i] = 1;
    	for (int j = 2 * i; j <= n; j += i) {
    		if (mark[j]) continue;
    		swap(a[j], a[prev]);
    		prev = j;
    		mark[j] = 1;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	cout << a[i] << " ";
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
