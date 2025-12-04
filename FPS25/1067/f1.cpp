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

void dfs(int node, vector<vector<pair<int, int>>>& g, vector<int>& path, vector<bool>& seen) {
	while (!g[node].empty()) {
		auto [son, idx] = g[node].back();
		g[node].pop_back();
		if (seen[idx]) { continue; }
		seen[idx] = true;
		dfs(son, g, path, seen);
	}
	path.push_back(node);
}
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
	vector<vector<pair<int, int>>> g;
	vector<int> path;
	vector<bool> seen;
    int n;
    cin >> n;

    int x = 0;
    for (int i = 1; i <= n; i++) {
    	int y;
    	if (i % 2) {
    		int j = (i + 1) / 2;
    		y = 2 * j * j - j;
    	} else {
    		int j = i / 2;
    		y = 2 * j * j + 1;
    	}
    	if (y >= n - 1) {
    		x = i;
    		break;
    	}
    }
    g.resize(x);
    int cnt = 0;
    for (int i = 0; i < x; i++) {
    	for (int j = i + 1; j < x; j++) {
    		if (x % 2 == 0 && i % 2 == 0 && j == i + 1) continue;
    		g[i].push_back({j, cnt});
    		g[j].push_back({i, cnt}); 
    		cnt++;   	
    	}
    }
    seen.resize(cnt);
    dfs(0, g, path, seen);
    if (x % 2 == 0) path.push_back(1);
    vi first(x, 1);
    vl ans;
    int sz = path.size();
    ll cur = 1ll << (x - 1);
    vl val(x);
    for (int i = 0; i < x; i++) {
    	val[i] = cur;
    	cur >>= 1;
    	cur *= 3;
    }
    for (int i = 0; i < sz; i++) {
    	int z = path[i];
    	if (first[z]) {
    		first[z] = 0;
    		ans.push_back({val[z]});
    	}
    	ans.push_back({val[z]});
    }
    set<ll> s;
    for (int i = 1; i < n; i++) {
    	ll g = gcd(ans[i], ans[i-1]);
    	//if (s.find(g) != s.end()) assert(false);
    	s.insert(g);
    }
    //assert(ans.size() >= n);
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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
