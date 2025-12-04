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
const ll MOD = 1e9+7;
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
void solve() {
    int n;
    cin >> n;
    vi c(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
    	cin >> b[i];
    }
    vi B(n);
    for (int i = 0; i < n - 1; i++) {
    	B[i + 1] = B[i] + b[i];
    }
    vi B2(n);
    for (int i = 0; i < n - 1; i++) {
    	B2[i + 1] = B2[i] + B[i+1];
    }
    vi C(n + 1);
    for (int i = 0; i < n; i++) {
    	C[i + 1] = C[i] + c[i];
    }
    vi V;
    for (int i = -9999; i <= 10000; i++) {
    	for (int j = 1; j <= 100; j++) {
    		// i + 9999 + j * 20000;
    		V.push_back(i + 9999 + j * 20000);
    	}
    }
    sort(V.begin(), V.end(), [&] (int u, int v) {
    	int y1 = u % 20000 - 9999;
    	int x1 = u / 20000;
    	int y2 = v % 20000;
    	int x2 = v / 20000;
    	if (1ll * y1 * x2 == 1ll * y2 * x1) {
    		return x1 > x2;
    	}
    	return 1ll * y1 * x2 < 1ll * y2 * x1;
    });
    int N = 2000000;
    vi ord(N);
    for (int i = 0; i < N; i++) {
    	ord[V[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
    	vector<mi> ldp(c[i] + 1, 1);
    	vector<mi> pldp(c[i] + 2);
    	for (int j = 0; j <= c[i]; j++) {
    		pldp[j+1] = pldp[j] + ldp[j];
    	}
    	swap(pldp, ldp);
    	for (int j = i + 1; j < n; j++) {
    		int tot = C[j + 1] - C[i];
    		vector<mi> nldp(tot + 1);
    		vector<mi> pnldp(tot + 2);
    		int L = j - i + 1;
    		int Btot = B2[j] - B2[i];
    		Btot -= B[i] * L;
    		for (int k = 0; k <= tot; k++) {
    			// low = (k - Btot) / L;
    			// hi = low + B[j] - B[i] = (k - Btot + (B[j] - B[i] * L)) / L;
    			int X = (k - Btot + (B[j] - B[i] * L));
    			int Y = L;
    			int Z = floor((float(X) + 0.001) / Y);
    			Z = min(Z, c[j]);
    			if (Z >= 0) {
    				// [k - Z, k];
    				int l = max(k - Z, 0);
    				int r = min(k, tot - c[j]);
    				nldp[k] += ldp[r] - ldp[l];
    			}
    			X += b[i] * L;
    		}
    		for (int k = 0; k <= tot; k++) {
    			pnldp[k+1] = pnldp[k] + nldp[k];
    		}

    	}
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
