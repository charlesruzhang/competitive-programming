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
int maxn = 2e5+1;
vvi facts(maxn);
void comp() {
	for (int x = 1; x <= maxn; x++) {
		for (int i = x; i <= maxn; i+=x) {
			facts[i].push_back(x);
		}	
	}
}
int B;
struct Q
{
    int x, y, idx;
    bool operator<(const Q & other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x; 
    }
};
void solve() {
	int q;
	cin >> q;
    B = trunc(sqrt(maxn));
	vector<Q> qrs(q);
    int idx = 0;
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        qrs[i] = Q(L, R, idx);
        idx++;
        ans[i] = 1ll * (R - L + 1) * (R - L) * (R - L - 1) / 6;
    	ans[i] -= max(0, (2 * R) / 12 - (4 * L - 1) / 12);
    	ans[i] -= max(0, (2 * R) / 30 - (5 * L - 1) / 30);
    }
    sort(qrs.begin(), qrs.end());
    int L = 1, R = 0;
    vi cnt(maxn);
    ll delta = 0;
    auto addR = [&](int u) {
        int l = 0;
        int r = facts[u].size() - 1;
        if (L == 1) {
            cnt[u] = facts[u].size() - 1;
            delta -= cnt[u] * (cnt[u] - 1) / 2;
            return;
        }
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (facts[u][m] < L) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        cnt[u] = facts[u].size() - 2 - l;
        delta -= cnt[u] * (cnt[u] - 1) / 2;
    };
    auto addL = [&](int u) {
        for (int i = 2 * u; i <= R; i += u) {
            delta -= cnt[i];
            cnt[i]++;
        }
    };
    auto removeR = [&](int u) {
        delta += cnt[u] * (cnt[u] - 1) / 2;
        cnt[u] = 0;
    };
    auto removeL = [&](int u) {
        for (int i = 2 * u; i <= R; i += u) {
            cnt[i]--;
            delta += cnt[i];
        }
    };
    for (auto& qr : qrs) {
        while (R < qr.y) addR(++R);
        while (L > qr.x) addL(--L);
        while (R > qr.y) removeR(R--);
        while (L < qr.x) removeL(L++);
        ans[qr.idx] += delta;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
