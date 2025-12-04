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
const int maxN = 4e4;
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
const ll M = 1e18;
ll query(ll x) {
	cout << "? " << x << endl;
	ll res;
	cin >> res;
	return res;
}
void solve() {
	int j = 0;
	vector<array<ll, 3>> last;
	map<int, int> ma;
    for (int i = 0; i < 22; i++) {
    	__int128 tot = 1;
    	vector<array<ll, 3>> req;
    	for (auto [u, v, k] : last) {
    		req.push_back({u * v, v, k + 1});
    		tot *= u * v;
    	}
    	last.resize(0);
    	while (tot * pvec[j] < M) {
    		tot *= pvec[j];
    		req.push_back({pvec[j], pvec[j], 1});
    		j++;
    	}
    	ll res = query(tot);
    	for (auto [r, p, k] : req) {
    		if (res % r == 0) {
    			last.push_back({r, p, k});
    			ma[p] = k;
    		}
    	}
    }
    auto it = ma.begin();
    ll ans = 1;
    while (it != ma.end()) {
    	auto [x, y] = *it;
    	ans *= (y + 1);
    	++it;
    }
    cout << "! " << 2 * ans << endl;
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
