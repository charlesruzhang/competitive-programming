// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
ll solve(int n, ll m, vi & a, vi & b) {
	int L = 2520;
    int j = 0;
    ll t = 0;
    vl ans(L * 100 +1);
    int z = 0;
    vi seen(10, -1);
    seen[0] = 0;
    ll cur = 0;
    int period = 0;
    int P = 0;
    int off = 0;
    while (1) {
    	ll prev = period * L;
    	while (cur - prev < L) {
	    	if ((cur + 1) % a[j] == b[j]) {
	    		z++;
	    	} else {
	    		z = 0;
	    		cur = cur + 1;
	    		ans[cur] = t + 1;
	    	}
	    	j = (j + 1) % n;
	    	t++;
	    	if (cur == m) {
	    		return t;
	    	}
	    	if (z >= n) {
	    		return -1;
	    	}
	    }
	    period++;
	    if (seen[j] != -1) {
	    	off = seen[j] * L;
	    	P = (period - seen[j]) * L;
	    	break;
	    }
	    seen[j] = period;
    }
    
    ll x = (m - off) / P;
    ll y = (m - off) % P;
    //cout << x << " " << y << " " << ans[off + P] - ans[off] << " " << ans[y + off] << endl;
    //cout << ans[off] << " " << x * (ans[off + P] - ans[off]) << " " << (ans[y + off] - ans[off]) << endl;
    return x * (ans[off + P] - ans[off]) + ans[y + off];
}

static const ll PHUGE = 2'727'000'000'000'000'000LL; // cap to avoid overflow (matches Kotlin)
static const int PLARGE = 1'000'000'727;             // large sentinel cost
static const int TAR = 2520;                         // lcm(1..10); used in original code
static const int MAXLOG = 60;                        // enough for m/2520 up to ~1e18

struct SimResult {
    int next_state; // endpoint state (or bad)
    int cost;       // steps spent locally
};

// simulate from state s for at most 'tar' accepted increments x
// acceptance rule: if ((x+1) % A[ns]) != B[ns], then x++
// always advance ns and local every step; stop when x == tar
// if loop count exceeds 10*tar+1, declare failure -> go to 'bad'
static SimResult simulate_one(int s,
                              int tar,
                              const vector<int>& A,
                              const vector<int>& B,
                              int n,
                              int bad_state)
{
    if (s == bad_state) return {bad_state, PLARGE};

    int ns = s;
    int x = 0;
    int local = 0;
    const int LIMIT = 10 * tar + 1;

    while (x < tar) {
        if (local == LIMIT) break;

        int attempt = x + 1;
        // guard: A[ns] should be positive in problem constraints
        if (A[ns] != 0) {
            if (attempt % A[ns] != B[ns]) {
                ++x;
            }
        } else {
            // If ever A[ns] == 0 (unlikely), we can never take attempt % 0.
            // Treat as "cannot accept", so just spin forward.
        }

        ++local;
        ++ns;
        if (ns == n) ns = 0;
    }

    if (local >= LIMIT) {
        return {bad_state, PLARGE};
    } else {
        return {ns, local};
    }
}
ll solve2(int n, ll m, vi& A, vi& B) {
	const int BAD = n;

        // go[i] = next node after consuming TAR "accepts" locally from i
        // cost0[i] = steps (local iterations) taken to achieve that
    vector<int> go(n + 1, BAD);
    vector<ll> cost0(n + 1, 0);

    // bad node loops to itself with large cost
    go[BAD] = BAD;
    cost0[BAD] = PLARGE;

    for (int s = 0; s < n; ++s) {
        SimResult r = simulate_one(s, TAR, A, B, n, BAD);
        go[s] = r.next_state;
        cost0[s] = r.cost;
    }

    // Binary lifting tables
    // up[k][i] = node reached after 2^k jumps from i
    // w[k][i]  = sum of costs over those 2^k jumps (capped)
    vector<array<int, MAXLOG + 1>> up(n + 1);
    vector<array<ll,  MAXLOG + 1>> w(n + 1);

    for (int i = 0; i <= n; ++i) {
        up[i][0] = go[i];
        w[i][0]  = cost0[i];
    }
    for (int k = 1; k <= MAXLOG; ++k) {
        for (int i = 0; i <= n; ++i) {
            int mid = up[i][k - 1];
            up[i][k] = up[mid][k - 1];
            __int128 sum = (__int128)w[i][k - 1] + (__int128)w[mid][k - 1];
            w[i][k] = (sum > PHUGE ? PHUGE : (ll)sum);
        }
    }

    auto lift = [&](int start, long long steps) -> pair<int, ll> {
        int node = start;
        ll acc = 0;
        for (int k = MAXLOG; k >= 0; --k) {
            if ((steps >> k) & 1LL) {
                acc = min(PHUGE, acc + w[node][k]);
                node = up[node][k];
            }
        }
        return {node, acc};
    };

    // m total attempts are split into full TAR-blocks and a final remainder
    long long rounds = m / TAR;
    auto [base_node, base_cost] = lift(0, rounds);

    int remainder = (int)(m - rounds * TAR);
    SimResult tail = simulate_one(base_node, remainder, A, B, n, BAD);

    if (tail.next_state == BAD) {
        return -1;
    } else {
       return (base_cost + (ll)tail.cost);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1000;
    mt19937 rng(100);
    while (t--) {
    	auto R = uniform_int_distribution<int>(1, 10);
    	int n = R(rng);

    	auto R2 = uniform_int_distribution<ll>(2520, 1e12);
    	auto R3 = uniform_int_distribution<int>(2, 10);
    	ll m = R2(rng);
    	vi a(n), b(n);
    	for (int i = 0; i < n; i++) {
    		a[i] = R3(rng);
    		auto R4 = uniform_int_distribution<int>(0, a[i] - 1);
    		b[i] = R4(rng);
    	}
    	ll x = solve(n, m, a, b);
    	ll y = solve2(n, m, a, b);
        if (x != y) {
        	cout << "??" << endl;
        	cout << n << " " << m << endl;
        	for (int i = 0; i < n; i++) {
	    		cout << a[i] << " " << b[i] << endl;
	    	} 
	    	cout << x << " " << y << endl;
	    	break;
        }
    }
    return 0;
}
