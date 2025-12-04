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
const int maxN = 1500000;
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
    ll l, r;
    cin >> l >> r;
    ll l2 = 2 * l;
    ll r2 = 2 * r;
    vi vec(r2 - l2 + 1, 1);
	for (int j = 0; j < pvec.size() && pvec[j] <= r2; j++) {
		int p = pvec[j];
		ll start = max(2ll * p, (l2 - 1) / p * p + p);
		for (ll i = start; i <= r2; i += p) {
			vec[i - l2] = 0;
		}
	}
	set<ll> s;
	set<ll, greater<>> t;
	for (int i = 0; i <= r2 - l2; i++) {
		if (vec[i]) {
			s.insert(i + l2);
			t.insert(i + l2);
		}
	}
	vi ans(r2 - l2 + 1);
	function <void(ll, ll)> find = [&](ll l, ll r) {
		//cout << l << " " << r << endl;
		auto it = s.lower_bound((r + l + 1) / 2);
		int flag = 0;
		if (it != s.end() &&  2 * (*it) >= l + r && (*it) < r) {
			find(l, *it);
		} else {
			flag++;
		}
		auto it2 = t.lower_bound((r + l) / 2); 
		if (it2 != t.end() && 2 * (*it2) <= l + r && (*it2) > l) {
			find(*it2, r);
		} else {
			flag++;
		}
		if (flag == 2) {
			ans[r - l]++;
		}
	};
	find(l2, r2);
	for (int i = 0; i < r2 - l2 + 1; i++) {
		if (ans[i] != 0) {
			cout << ans[i] << endl;
			return;
		} 
	}
	assert(false);
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
