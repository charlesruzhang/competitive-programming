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
const int maxN = 2e5+2;
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi facts;
    for (int i = 2; i < n; i++) {
    	if (primes[i] && (n % i == 0)) {
    		facts.push_back(i);
    	}
    }
    sort(facts.begin(), facts.end());
    int m = facts.size();
    vector<multiset<ll, greater<>>> vms(m);
    vvl tot(m);
    ll maxx = 0;
    for (int i = 0; i < m; i++) {
    	int x = n / facts[i];
    	for (int j = 0; j < x; j++) {
    		ll summ = 0;
    		for (int k = j; k < n; k += x) {
    			summ += a[k];
    		}
    		summ *= x;
    		vms[i].insert(summ);
    		tot[i].push_back(summ);
    	}
    	maxx = max(maxx, *(vms[i].begin()));
    }
    ll S = accumulate(a.begin(), a.end(), 0ll);
    maxx = max(maxx, S);
    cout << maxx << '\n';
    for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		p--;
		int diff = x - a[p];
		maxx = 0;
		for (int j = 0; j < m; j++) {
			int y = n / facts[j];
			int idx = p % y;
			ll ori = tot[j][idx];
			vms[j].erase(vms[j].find(ori));
			tot[j][idx] = ori + 1ll * y * diff;
			vms[j].insert(ori + 1ll * y * diff);
			maxx = max(maxx, *(vms[j].begin()));
		}
		S += diff;
		a[p] = x;
		maxx = max(maxx, S);
		cout << maxx << '\n';
    }
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
