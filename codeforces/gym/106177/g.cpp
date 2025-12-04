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

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int N = 1e6+1;
vvi facts(N);
void comp() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j+=i) {
			facts[j].push_back(i);
		}
	}
}
ll lcm(int x, int y) {
	return 1ll * x * y / gcd(x, y);
}
vi M(N, -1);
void solve() {
    int n, z;
    cin >> n >> z;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (n == 1) {
    	int g = gcd(z, a[0]);
    	if (g == lcm(z, a[0])) {
    		cout << g << " " << 2 << endl;
    	} else {
    		cout << g << " " << 1 << endl;
    	}
    	return;
    }
    vector<map<int, mi>> vm(n + 1);
    vm[0][z] = 1;
    for (int v : facts[z]) {
    	M[v] = 0;
    }
    vector<mi> pref(n + 1);
    pref[0] = 1;

	for (auto [x, W]: vm[0]) {
		//cout << 0 << "! " << x << " " << (int)W << endl;
	}
    for (int i = 0; i < n; i++) {
    	vector<pii> w;
    	for (int v : facts[a[i]]) {
    		w.push_back({M[v], v});
    	}
    	sort(w.begin(), w.end(), greater<>());
    	int cur = 1;
    	int loc = i;
    	mi T = 0;
    	auto& m2 = vm[i+1];
    	for (auto [m, v] : w) {
    		//cout << i << " " << m << " " << v << " " << loc << endl;
    		if (m > loc) continue;
    		if (m < 0 || loc < 0) break;
    		if (loc != m) {
	    		mi Z = pref[loc] - pref[m];
	    		T += Z;
	    		m2[cur] += Z;
    		}
    		//cout << "???" << i + 1 << " " << cur << " " << (int) Z << endl;
    		if (i == 0 || m != i) {
    			auto& m1 = vm[m];
	    		for (auto [x, W]: m1) {
	    			m2[gcd(lcm(x, cur), a[i])] += W;
					T += W;
	    		}
    		}
    		cur = lcm(cur, v);
    		loc = m - 1;
    		if (cur == a[i]) break;
    	}
    	if (loc >= 0) {
    		int z = max(min(loc, i - 1), 0);
    		m2[cur] += pref[z];
    		T += pref[z];
    	}
    	for (int v : facts[a[i]]) {
    		M[v] = i + 1;
    	}
    	pref[i + 1] = pref[i] + T;
    	for (auto [x, W]: m2) {
    		//cout << i + 1 << "! " << x << " " << (int)W << endl;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int v : facts[a[i]]) {
    		M[v] = -1;
    	}
    }
    for (int v : facts[z]) {
    	M[v] = -1;
    }
    auto [x, V] = *(vm[n].begin());
    mi ans = 0;
    int G = x;
    for (int i = n; i >= 0; i--) {
    	auto & m1 = vm[i];
    	for (auto [x, W]: m1) {
    		if (lcm(G, x) == G) ans += W;
    	}
    	G = lcm(G, (i ? a[i - 1] : z));
    	if (G != x) {
    		break;
    	}
    }
    cout << x << " " << (int) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
