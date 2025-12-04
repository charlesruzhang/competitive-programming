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
vi prime;
const int maxN = 1e7+5;
bool is_composite[maxN];
int P[maxN];
void sieve () {
	int n = maxN;
	std::fill (is_composite, is_composite + n, false);
	std::fill (P, P + n, -1);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	for (int p : prime) {
		for (int j = p; j < n; j+=p) {
			P[j] = p;
		}
	}
}
void solve() {
    int n;
    cin >> n;
    vi d1(n);
    vi d2(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	int y = x;
    	int z = P[x];
    	while (1) {
    		if (x % z) break;
    		x /= z;
    	}
    	if (x != 1) {
    		d1[i] = x;
    		d2[i] = y / x;
    	} else {
    		d1[i] = d2[i] = -1;
    	}

    }
    for (int i = 0; i < n; i++) {
    	cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
    	cout << d2[i] << " ";
    }
    cout << endl;
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
