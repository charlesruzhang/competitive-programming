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
const int maxN = 5e3+1;
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
    vi a(n);
    int N = 5000;
    vi C(2 * N + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        if (a[i] == 0) a[i]++;
    	C[a[i]]++;
    }
    int sz = pvec.size();
    vi prev(sz);
    vi now(sz);
    vi idx(N + 1);
    for (int i = 0; i < sz; i++) {
    	idx[pvec[i]] = i;
    }

	vector<vector<pii>> f(N + 1);
    stack<pii> st;
    st.push({1, 0});
    int timer = N + 1;
    vi summ(N + 1);
    for (int i = 2; i <= N; i++) {
    	int x = i;
    	vi vec;
    	for (int j = 2; j * j <= x; j++) {
    		while (x % j == 0) {
    			x /= j;
    			vec.push_back(j);
    		}
    	}
    	if (x > 1) {
    		vec.push_back(x);
    	}
    	summ[i] = summ[i-1];
    	for (int y : vec) {
    		now[idx[y]]++;
    		summ[i] ++;
    	}
    	int cnt = 0;
    	for (int j = sz - 1; j >= 0; j--) {
    		cnt += prev[j];
    		if (now[j] != prev[j]) {
    			break;
    		}
    	}
    	while (cnt < st.top().second) {
			auto [y, dep] = st.top();
			st.pop();
			if (cnt >= st.top().second) {
				int x = timer;
				if (cnt > st.top().second) {
	    			st.push({timer++, cnt});
	    			f.push_back({});
	    		} else {
	    			x = st.top().first;
	    		}
    			f[y].push_back({x, dep - cnt});
    			f[x].push_back({y, dep - cnt});
			} else {
				auto [z, d2] = st.top();
				f[y].push_back({z, dep - d2});
				f[z].push_back({y, dep - d2});
			}
		}
		st.push({i, summ[i]});
		for (int y : vec) {
    		prev[idx[y]]++;
    	}
    }
    while (st.size() >= 2) {
		auto [v, d1] = st.top();
		st.pop();
		auto [u, d2] = st.top();
		f[v].push_back({u, d1 - d2});
		f[u].push_back({v, d1 - d2});
	}
	int szz = f.size(); 
	vl subw(szz, 0);
	vl cost(szz, 0);
	ll W = 0;
	for (int i = 1; i < szz; i++) {
		W += C[i];
	}
    ll base = 0;
    ll cur = 0;
    function <void(int, int)> dfs1 = [&](int u, int p) {
        subw[u] = C[u];
        base += C[u] * cur;
        for (auto &[v, w] : f[u]) {
        	if (v != p) {
	        	cur += w;
	            dfs1(v, u);
	            cur -= w;
	            subw[u] += subw[v];
        	}
        }
    };
    dfs1(1, -1);
    cost[1] = base;

    function <void(int, int)> dfs2 = [&](int u, int p) {
        for (auto &[v, w] : f[u]) {
        	if (v != p) {
            	cost[v] = cost[u] + w * (W - 2 * subw[v]);
            	dfs2(v, u);
        	}
        }
    };
    dfs2(1, -1);

    ll ret = 1e18;
    for (int i = 1; i < szz; i++) {
        ret = min(cost[i], ret);
    }
	cout << ret << endl;
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
