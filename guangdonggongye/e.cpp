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
const int maxN = 1e4;
vvi E(maxN);
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
    for (int p : pvec) {
    	int x = p;
    	vi a;
    	for (int i = 0; i < 4; i++) {
    		a.push_back(x % 10);
    		x/=10;
    	}
    	int cur = 1;
    	for (int i = 0; i < 4; i++) {
    		for (int j = 0; j < 10; j++) {
    			if (a[i] == j) continue;
    			int y = p + (-a[i] + j) * cur;
    			if (primes[y]) {
    				E[p].push_back(y);
    				//cout << p << " " << y << endl;
    			}
    		}
    		cur *= 10;
    	}
    }
}
void solve() {
	int p, b;
	cin >> p >> b;
	vi vis(10000);
	queue<pii> q;
	q.push({0, p});
	vis[p] = 1;
	while (!q.empty()) {
		auto [x, u] = q.front();
		q.pop();
		if (u == b) {
			cout << x << endl;
			return;
		}
		for (int v : E[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push({x + 1, v});
			}
		}
	}
	cout << -1 << endl;
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
