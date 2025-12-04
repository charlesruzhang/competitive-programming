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
const int maxN = 1e6;
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
    //cout << pvec.size() << endl;
}
void solve() {
	int N = 1e6;
    vvi facts(N+1);
    for (int i = 2; i <= N; i++) {
    	if (facts[i].size()) continue;
    	for (int j = i; j <= N; j+=i) {
    		facts[j].push_back(i);
    	}
    }
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    set<ll> s;
    int flag = INF;
    vvi e(1e6+1);
    vi P;
    for (int i = 0; i < n; i++) {
    	int y = a[i];
    	int tot = 1;
    	vi vv;
    	for (int x : facts[a[i]]) {
			int cnt = 0;
    		while (y % x == 0) {
    			y /= x;
    			cnt++;
    		}
    		assert(cnt != 0);
    		if (cnt % 2 == 1) {
    			tot *= x; 
    			vv.push_back(x);
    		}
    	}
    	if (tot == 1) {
    		cout << 1 << endl;
    		return;
    	}
    	if (s.find(tot) != s.end()) {
    		flag = min(flag, 2);
    	} else {
    		s.insert(tot);
    		if (vv.size() == 1) {
    			e[1].push_back(tot);
    			e[tot].push_back(1);
    		} else {
    			int x = vv[0];
    			int y = vv[1];
    			e[x].push_back(y);
    			e[y].push_back(x);
    		}
    	}
    }
    if (flag == 2) {
    	cout << flag << endl;
    	return;
    }
    vi dist(N+1);
    vi vis(N+1);
    for (int i = 1; i * i <= N; i++) {
    	if (e[i].size() && !vis[i]) {
    		queue<pii> q;
    		q.push({i, -1});
    		vis[i] = 1;
    		vi V;
    		V.push_back(i);
    		while (!q.empty()) {
    			auto [u, p] = q.front();
    			q.pop();
    			for (int v : e[u]) {
    				if (v == p) continue;
    				if (vis[v]) {
    					flag = min(flag, dist[u] + dist[v] + 1);
    				} else {
    					q.push({v, u});
    					vis[v] = 1;
    					V.push_back(v);
    					dist[v] = dist[u] + 1;
    				}
    			}
    		}
    		for (int x : V) {
    			vis[x] = 0;
    			dist[x] = 0;
    		}
    	}
    }	
    if (flag == INF) {
    	cout << -1 << endl;
    } else {
    	cout << flag << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
